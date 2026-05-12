clear; clc; close all;

folder = 'D:\WORK\school\cls\movepartom\ur';
urdf   = fullfile(folder,'ur5.urdf');
assert(exist(urdf,'file')==2, 'URDF not found: %s', urdf);

robot = importrobot(urdf);

%% 1) 读取关节顺序与限位（按 URDF 的关节顺序）
robot.DataFormat = 'struct';
cfg = homeConfiguration(robot);           % struct array
jointNames = {cfg.JointName};

qlim = zeros(numel(cfg),2);
for i = 1:numel(cfg)
    found = false;
    for b = 1:numel(robot.Bodies)
        j = robot.Bodies{b}.Joint;
        if strcmp(j.Name, jointNames{i})
            qlim(i,:) = j.PositionLimits; % [min max] rad
            found = true;
            break;
        end
    end
    assert(found, 'Joint not found: %s', jointNames{i});
end

%% 2) 选择末端 link
robot.DataFormat = 'row';
ee = 'tool0';
if ~any(strcmp(robot.BodyNames, ee))
    ee = robot.BodyNames{end};
end

%% 3) 随机采样工作空间点云（忽略碰撞）
N = 500000;  % 点数：越大越密，越慢
Q = qlim(:,1)' + rand(N,6).*(qlim(:,2)'-qlim(:,1)');   % N×6
P = zeros(N,3);
-
+-----------+
for k = 1:N
    T = getTransform(robot, Q(k,:), ee);
    P(k,:) = tform2trvec(T);  % [x y z] m  
end

%% 4) 可视化
figure;
h = scatter3(P(:,1), P(:,2), P(:,3), 0.5, '.');  % 点更小
h.MarkerEdgeAlpha = 0.08;                         % 透明，避免糊
axis equal; grid on; view(3);
xlabel('x / m'); ylabel('y / m'); zlabel('z / m');
title(sprintf('UR5 Workspace Point Cloud (N=%d)', N));

%% 5) 计算“运行半径”（到 base 原点距离）
r = sqrt(sum(P.^2,2));
r_max = max(r);
r_min = min(r);
r_95  = prctile(r,95);
[~, idx] = max(r);
p_far = P(idx,:);

fprintf('r_min = %.4f m\n', r_min);
fprintf('r_95  = %.4f m\n', r_95);
fprintf('r_max = %.4f m, farthest point = [%.4f %.4f %.4f] m\n', r_max, p_far(1), p_far(2), p_far(3));

% 若只看水平半径（XY 平面）
r_xy_max = max(hypot(P(:,1), P(:,2)));
fprintf('r_xy_max = %.4f m\n', r_xy_max);
