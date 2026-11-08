#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_2427570131299459704) {
   out_2427570131299459704[0] = delta_x[0] + nom_x[0];
   out_2427570131299459704[1] = delta_x[1] + nom_x[1];
   out_2427570131299459704[2] = delta_x[2] + nom_x[2];
   out_2427570131299459704[3] = delta_x[3] + nom_x[3];
   out_2427570131299459704[4] = delta_x[4] + nom_x[4];
   out_2427570131299459704[5] = delta_x[5] + nom_x[5];
   out_2427570131299459704[6] = delta_x[6] + nom_x[6];
   out_2427570131299459704[7] = delta_x[7] + nom_x[7];
   out_2427570131299459704[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_122641313029076524) {
   out_122641313029076524[0] = -nom_x[0] + true_x[0];
   out_122641313029076524[1] = -nom_x[1] + true_x[1];
   out_122641313029076524[2] = -nom_x[2] + true_x[2];
   out_122641313029076524[3] = -nom_x[3] + true_x[3];
   out_122641313029076524[4] = -nom_x[4] + true_x[4];
   out_122641313029076524[5] = -nom_x[5] + true_x[5];
   out_122641313029076524[6] = -nom_x[6] + true_x[6];
   out_122641313029076524[7] = -nom_x[7] + true_x[7];
   out_122641313029076524[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_7941775136222393929) {
   out_7941775136222393929[0] = 1.0;
   out_7941775136222393929[1] = 0.0;
   out_7941775136222393929[2] = 0.0;
   out_7941775136222393929[3] = 0.0;
   out_7941775136222393929[4] = 0.0;
   out_7941775136222393929[5] = 0.0;
   out_7941775136222393929[6] = 0.0;
   out_7941775136222393929[7] = 0.0;
   out_7941775136222393929[8] = 0.0;
   out_7941775136222393929[9] = 0.0;
   out_7941775136222393929[10] = 1.0;
   out_7941775136222393929[11] = 0.0;
   out_7941775136222393929[12] = 0.0;
   out_7941775136222393929[13] = 0.0;
   out_7941775136222393929[14] = 0.0;
   out_7941775136222393929[15] = 0.0;
   out_7941775136222393929[16] = 0.0;
   out_7941775136222393929[17] = 0.0;
   out_7941775136222393929[18] = 0.0;
   out_7941775136222393929[19] = 0.0;
   out_7941775136222393929[20] = 1.0;
   out_7941775136222393929[21] = 0.0;
   out_7941775136222393929[22] = 0.0;
   out_7941775136222393929[23] = 0.0;
   out_7941775136222393929[24] = 0.0;
   out_7941775136222393929[25] = 0.0;
   out_7941775136222393929[26] = 0.0;
   out_7941775136222393929[27] = 0.0;
   out_7941775136222393929[28] = 0.0;
   out_7941775136222393929[29] = 0.0;
   out_7941775136222393929[30] = 1.0;
   out_7941775136222393929[31] = 0.0;
   out_7941775136222393929[32] = 0.0;
   out_7941775136222393929[33] = 0.0;
   out_7941775136222393929[34] = 0.0;
   out_7941775136222393929[35] = 0.0;
   out_7941775136222393929[36] = 0.0;
   out_7941775136222393929[37] = 0.0;
   out_7941775136222393929[38] = 0.0;
   out_7941775136222393929[39] = 0.0;
   out_7941775136222393929[40] = 1.0;
   out_7941775136222393929[41] = 0.0;
   out_7941775136222393929[42] = 0.0;
   out_7941775136222393929[43] = 0.0;
   out_7941775136222393929[44] = 0.0;
   out_7941775136222393929[45] = 0.0;
   out_7941775136222393929[46] = 0.0;
   out_7941775136222393929[47] = 0.0;
   out_7941775136222393929[48] = 0.0;
   out_7941775136222393929[49] = 0.0;
   out_7941775136222393929[50] = 1.0;
   out_7941775136222393929[51] = 0.0;
   out_7941775136222393929[52] = 0.0;
   out_7941775136222393929[53] = 0.0;
   out_7941775136222393929[54] = 0.0;
   out_7941775136222393929[55] = 0.0;
   out_7941775136222393929[56] = 0.0;
   out_7941775136222393929[57] = 0.0;
   out_7941775136222393929[58] = 0.0;
   out_7941775136222393929[59] = 0.0;
   out_7941775136222393929[60] = 1.0;
   out_7941775136222393929[61] = 0.0;
   out_7941775136222393929[62] = 0.0;
   out_7941775136222393929[63] = 0.0;
   out_7941775136222393929[64] = 0.0;
   out_7941775136222393929[65] = 0.0;
   out_7941775136222393929[66] = 0.0;
   out_7941775136222393929[67] = 0.0;
   out_7941775136222393929[68] = 0.0;
   out_7941775136222393929[69] = 0.0;
   out_7941775136222393929[70] = 1.0;
   out_7941775136222393929[71] = 0.0;
   out_7941775136222393929[72] = 0.0;
   out_7941775136222393929[73] = 0.0;
   out_7941775136222393929[74] = 0.0;
   out_7941775136222393929[75] = 0.0;
   out_7941775136222393929[76] = 0.0;
   out_7941775136222393929[77] = 0.0;
   out_7941775136222393929[78] = 0.0;
   out_7941775136222393929[79] = 0.0;
   out_7941775136222393929[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_6974798855676325195) {
   out_6974798855676325195[0] = state[0];
   out_6974798855676325195[1] = state[1];
   out_6974798855676325195[2] = state[2];
   out_6974798855676325195[3] = state[3];
   out_6974798855676325195[4] = state[4];
   out_6974798855676325195[5] = dt*(stiffness_front*(-state[2] - state[3] + state[7])*state[0]/state[1] + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/state[4] + ((-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/state[4] - state[4])*state[6] - 9.8100000000000005*state[8]) + state[5];
   out_6974798855676325195[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_6974798855676325195[7] = state[7];
   out_6974798855676325195[8] = state[8];
}
void F_fun(double *state, double dt, double *out_1556117237806562757) {
   out_1556117237806562757[0] = 1;
   out_1556117237806562757[1] = 0;
   out_1556117237806562757[2] = 0;
   out_1556117237806562757[3] = 0;
   out_1556117237806562757[4] = 0;
   out_1556117237806562757[5] = 0;
   out_1556117237806562757[6] = 0;
   out_1556117237806562757[7] = 0;
   out_1556117237806562757[8] = 0;
   out_1556117237806562757[9] = 0;
   out_1556117237806562757[10] = 1;
   out_1556117237806562757[11] = 0;
   out_1556117237806562757[12] = 0;
   out_1556117237806562757[13] = 0;
   out_1556117237806562757[14] = 0;
   out_1556117237806562757[15] = 0;
   out_1556117237806562757[16] = 0;
   out_1556117237806562757[17] = 0;
   out_1556117237806562757[18] = 0;
   out_1556117237806562757[19] = 0;
   out_1556117237806562757[20] = 1;
   out_1556117237806562757[21] = 0;
   out_1556117237806562757[22] = 0;
   out_1556117237806562757[23] = 0;
   out_1556117237806562757[24] = 0;
   out_1556117237806562757[25] = 0;
   out_1556117237806562757[26] = 0;
   out_1556117237806562757[27] = 0;
   out_1556117237806562757[28] = 0;
   out_1556117237806562757[29] = 0;
   out_1556117237806562757[30] = 1;
   out_1556117237806562757[31] = 0;
   out_1556117237806562757[32] = 0;
   out_1556117237806562757[33] = 0;
   out_1556117237806562757[34] = 0;
   out_1556117237806562757[35] = 0;
   out_1556117237806562757[36] = 0;
   out_1556117237806562757[37] = 0;
   out_1556117237806562757[38] = 0;
   out_1556117237806562757[39] = 0;
   out_1556117237806562757[40] = 1;
   out_1556117237806562757[41] = 0;
   out_1556117237806562757[42] = 0;
   out_1556117237806562757[43] = 0;
   out_1556117237806562757[44] = 0;
   out_1556117237806562757[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/state[1] + (-stiffness_front - stiffness_rear)*state[5]/state[4] + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/state[4]);
   out_1556117237806562757[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/pow(state[1], 2);
   out_1556117237806562757[47] = -dt*stiffness_front*state[0]/state[1];
   out_1556117237806562757[48] = -dt*stiffness_front*state[0]/state[1];
   out_1556117237806562757[49] = dt*(-(-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/pow(state[4], 2) + (-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/pow(state[4], 2) - 1)*state[6]);
   out_1556117237806562757[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/state[4] + 1;
   out_1556117237806562757[51] = dt*((-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/state[4] - state[4]);
   out_1556117237806562757[52] = dt*stiffness_front*state[0]/state[1];
   out_1556117237806562757[53] = -9.8100000000000005*dt;
   out_1556117237806562757[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_1556117237806562757[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_1556117237806562757[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_1556117237806562757[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_1556117237806562757[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_1556117237806562757[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_1556117237806562757[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_1556117237806562757[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_1556117237806562757[62] = 0;
   out_1556117237806562757[63] = 0;
   out_1556117237806562757[64] = 0;
   out_1556117237806562757[65] = 0;
   out_1556117237806562757[66] = 0;
   out_1556117237806562757[67] = 0;
   out_1556117237806562757[68] = 0;
   out_1556117237806562757[69] = 0;
   out_1556117237806562757[70] = 1;
   out_1556117237806562757[71] = 0;
   out_1556117237806562757[72] = 0;
   out_1556117237806562757[73] = 0;
   out_1556117237806562757[74] = 0;
   out_1556117237806562757[75] = 0;
   out_1556117237806562757[76] = 0;
   out_1556117237806562757[77] = 0;
   out_1556117237806562757[78] = 0;
   out_1556117237806562757[79] = 0;
   out_1556117237806562757[80] = 1;
}
void h_25(double *state, double *unused, double *out_2762423067770022742) {
   out_2762423067770022742[0] = state[6];
}
void H_25(double *state, double *unused, double *out_5601277112302492847) {
   out_5601277112302492847[0] = 0;
   out_5601277112302492847[1] = 0;
   out_5601277112302492847[2] = 0;
   out_5601277112302492847[3] = 0;
   out_5601277112302492847[4] = 0;
   out_5601277112302492847[5] = 0;
   out_5601277112302492847[6] = 1;
   out_5601277112302492847[7] = 0;
   out_5601277112302492847[8] = 0;
}
void h_24(double *state, double *unused, double *out_1315832138671900521) {
   out_1315832138671900521[0] = state[4];
   out_1315832138671900521[1] = state[5];
}
void H_24(double *state, double *unused, double *out_3424062688695342874) {
   out_3424062688695342874[0] = 0;
   out_3424062688695342874[1] = 0;
   out_3424062688695342874[2] = 0;
   out_3424062688695342874[3] = 0;
   out_3424062688695342874[4] = 1;
   out_3424062688695342874[5] = 0;
   out_3424062688695342874[6] = 0;
   out_3424062688695342874[7] = 0;
   out_3424062688695342874[8] = 0;
   out_3424062688695342874[9] = 0;
   out_3424062688695342874[10] = 0;
   out_3424062688695342874[11] = 0;
   out_3424062688695342874[12] = 0;
   out_3424062688695342874[13] = 0;
   out_3424062688695342874[14] = 1;
   out_3424062688695342874[15] = 0;
   out_3424062688695342874[16] = 0;
   out_3424062688695342874[17] = 0;
}
void h_30(double *state, double *unused, double *out_7921055749118856433) {
   out_7921055749118856433[0] = state[4];
}
void H_30(double *state, double *unused, double *out_3082944153795244220) {
   out_3082944153795244220[0] = 0;
   out_3082944153795244220[1] = 0;
   out_3082944153795244220[2] = 0;
   out_3082944153795244220[3] = 0;
   out_3082944153795244220[4] = 1;
   out_3082944153795244220[5] = 0;
   out_3082944153795244220[6] = 0;
   out_3082944153795244220[7] = 0;
   out_3082944153795244220[8] = 0;
}
void h_26(double *state, double *unused, double *out_1543719152583854418) {
   out_1543719152583854418[0] = state[7];
}
void H_26(double *state, double *unused, double *out_9103963642533002545) {
   out_9103963642533002545[0] = 0;
   out_9103963642533002545[1] = 0;
   out_9103963642533002545[2] = 0;
   out_9103963642533002545[3] = 0;
   out_9103963642533002545[4] = 0;
   out_9103963642533002545[5] = 0;
   out_9103963642533002545[6] = 0;
   out_9103963642533002545[7] = 1;
   out_9103963642533002545[8] = 0;
}
void h_27(double *state, double *unused, double *out_8681558302146463095) {
   out_8681558302146463095[0] = state[3];
}
void H_27(double *state, double *unused, double *out_859350082611301003) {
   out_859350082611301003[0] = 0;
   out_859350082611301003[1] = 0;
   out_859350082611301003[2] = 0;
   out_859350082611301003[3] = 1;
   out_859350082611301003[4] = 0;
   out_859350082611301003[5] = 0;
   out_859350082611301003[6] = 0;
   out_859350082611301003[7] = 0;
   out_859350082611301003[8] = 0;
}
void h_29(double *state, double *unused, double *out_5524015056929849538) {
   out_5524015056929849538[0] = state[1];
}
void H_29(double *state, double *unused, double *out_2572712809480852036) {
   out_2572712809480852036[0] = 0;
   out_2572712809480852036[1] = 1;
   out_2572712809480852036[2] = 0;
   out_2572712809480852036[3] = 0;
   out_2572712809480852036[4] = 0;
   out_2572712809480852036[5] = 0;
   out_2572712809480852036[6] = 0;
   out_2572712809480852036[7] = 0;
   out_2572712809480852036[8] = 0;
}
void h_28(double *state, double *unused, double *out_443627665315179562) {
   out_443627665315179562[0] = state[0];
}
void H_28(double *state, double *unused, double *out_7655111826550382610) {
   out_7655111826550382610[0] = 1;
   out_7655111826550382610[1] = 0;
   out_7655111826550382610[2] = 0;
   out_7655111826550382610[3] = 0;
   out_7655111826550382610[4] = 0;
   out_7655111826550382610[5] = 0;
   out_7655111826550382610[6] = 0;
   out_7655111826550382610[7] = 0;
   out_7655111826550382610[8] = 0;
}
void h_31(double *state, double *unused, double *out_7803048355185479689) {
   out_7803048355185479689[0] = state[8];
}
void H_31(double *state, double *unused, double *out_5570631150425532419) {
   out_5570631150425532419[0] = 0;
   out_5570631150425532419[1] = 0;
   out_5570631150425532419[2] = 0;
   out_5570631150425532419[3] = 0;
   out_5570631150425532419[4] = 0;
   out_5570631150425532419[5] = 0;
   out_5570631150425532419[6] = 0;
   out_5570631150425532419[7] = 0;
   out_5570631150425532419[8] = 1;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_2427570131299459704) {
  err_fun(nom_x, delta_x, out_2427570131299459704);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_122641313029076524) {
  inv_err_fun(nom_x, true_x, out_122641313029076524);
}
void car_H_mod_fun(double *state, double *out_7941775136222393929) {
  H_mod_fun(state, out_7941775136222393929);
}
void car_f_fun(double *state, double dt, double *out_6974798855676325195) {
  f_fun(state,  dt, out_6974798855676325195);
}
void car_F_fun(double *state, double dt, double *out_1556117237806562757) {
  F_fun(state,  dt, out_1556117237806562757);
}
void car_h_25(double *state, double *unused, double *out_2762423067770022742) {
  h_25(state, unused, out_2762423067770022742);
}
void car_H_25(double *state, double *unused, double *out_5601277112302492847) {
  H_25(state, unused, out_5601277112302492847);
}
void car_h_24(double *state, double *unused, double *out_1315832138671900521) {
  h_24(state, unused, out_1315832138671900521);
}
void car_H_24(double *state, double *unused, double *out_3424062688695342874) {
  H_24(state, unused, out_3424062688695342874);
}
void car_h_30(double *state, double *unused, double *out_7921055749118856433) {
  h_30(state, unused, out_7921055749118856433);
}
void car_H_30(double *state, double *unused, double *out_3082944153795244220) {
  H_30(state, unused, out_3082944153795244220);
}
void car_h_26(double *state, double *unused, double *out_1543719152583854418) {
  h_26(state, unused, out_1543719152583854418);
}
void car_H_26(double *state, double *unused, double *out_9103963642533002545) {
  H_26(state, unused, out_9103963642533002545);
}
void car_h_27(double *state, double *unused, double *out_8681558302146463095) {
  h_27(state, unused, out_8681558302146463095);
}
void car_H_27(double *state, double *unused, double *out_859350082611301003) {
  H_27(state, unused, out_859350082611301003);
}
void car_h_29(double *state, double *unused, double *out_5524015056929849538) {
  h_29(state, unused, out_5524015056929849538);
}
void car_H_29(double *state, double *unused, double *out_2572712809480852036) {
  H_29(state, unused, out_2572712809480852036);
}
void car_h_28(double *state, double *unused, double *out_443627665315179562) {
  h_28(state, unused, out_443627665315179562);
}
void car_H_28(double *state, double *unused, double *out_7655111826550382610) {
  H_28(state, unused, out_7655111826550382610);
}
void car_h_31(double *state, double *unused, double *out_7803048355185479689) {
  h_31(state, unused, out_7803048355185479689);
}
void car_H_31(double *state, double *unused, double *out_5570631150425532419) {
  H_31(state, unused, out_5570631150425532419);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_lib_init(car)
