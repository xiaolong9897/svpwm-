clear; clc;

urdf = 'D:\WORK\school\cls\movepartom\ur\ur5.urdf';
robot = importrobot(urdf);
robot.Gravity = [0 0 -9.81];

% 关节顺序（struct 才有 JointName）
robot.DataFormat = 'struct';
cfgs = homeConfiguration(robot);
joint_order = {cfgs.JointName}';
disp('Joint order:');
disp(joint_order);

% 重力补偿测试（row 更方便喂 q 向量）
robot.DataFormat = 'row';
q = [0 -pi/2 pi/2 0 0 0];

tau_g1 = gravityTorque(robot, q);
tau_g2 = inverseDynamics(robot, q, zeros(1,6), zeros(1,6));

disp('tau_g1 ='); disp(tau_g1);
disp('tau_g2 ='); disp(tau_g2);
