function [q_ref, status, p_fk, pos_err] = ur5_ik_xyz(q_now, p_des, urdf_path)
%UR5_IK_XYZ Position-only numerical IK using the same UR5 DH FK as the model.
%   q_now : 1x6 or 6x1 current joint angles, unit rad.
%   p_des : 1x3 or 3x1 desired tool position, unit m.
%   urdf_path is unused and kept only for old interface compatibility.
%
%   q_ref   : 1x6 IK solution, unit rad.
%   status  : 1 = converged, 0 = best available.
%   p_fk    : 1x3 FK position at q_ref, unit m.
%   pos_err : norm(p_fk - p_des), unit m.

%#ok<*INUSD>

q = q_now(:).';
p = p_des(:).';

max_iter = 60;
tol = 1e-4;
lambda = 0.03;
max_step = 0.15;

status = 0;

for k = 1:max_iter
    p_now = ur5e_fk_local(q);
    err = p - p_now;
    pos_err = norm(err);

    if pos_err < tol
        status = 1;
        break;
    end

    J = jacobian_pos(q);
    dq = J' * ((J * J' + lambda * lambda * eye(3)) \ err(:));

    step = max(abs(dq));
    if step > max_step
        dq = dq * (max_step / step);
    end

    q = q + dq.';
end

q_ref = q;
p_fk = ur5e_fk_local(q_ref);
pos_err = norm(p_fk - p);

if pos_err < tol
    status = 1;
end
end

function J = jacobian_pos(q)
eps_q = 1e-6;
J = zeros(3,6);
p0 = ur5e_fk_local(q);

for i = 1:6
    q1 = q;
    q1(i) = q1(i) + eps_q;
    p1 = ur5e_fk_local(q1);
    J(:,i) = (p1(:) - p0(:)) / eps_q;
end
end

function p = ur5e_fk_local(q)
q1 = q(1);
q2 = q(2);
q3 = q(3);
q4 = q(4);
q5 = q(5);
q6 = q(6);

d1 = 0.089159;
a2 = -0.425;
a3 = -0.39225;
d4 = 0.10915;
d5 = 0.09465;
d6 = 0.0823;

T = eye(4);
T = T * dh(0,  pi/2, d1, q1);
T = T * dh(a2, 0,    0,  q2);
T = T * dh(a3, 0,    0,  q3);
T = T * dh(0,  pi/2, d4, q4);
T = T * dh(0, -pi/2, d5, q5);
T = T * dh(0,  0,    d6, q6);

p_dh = T(1:3,4).';
p = [-p_dh(1), -p_dh(2), p_dh(3)];
end

function A = dh(a, alpha, d, theta)
ct = cos(theta);
st = sin(theta);
ca = cos(alpha);
sa = sin(alpha);

A = [ct, -st*ca,  st*sa, a*ct;
     st,  ct*ca, -ct*sa, a*st;
     0,      sa,     ca,    d;
     0,       0,      0,    1];
end
