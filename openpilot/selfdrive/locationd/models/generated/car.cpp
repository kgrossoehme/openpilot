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
void err_fun(double *nom_x, double *delta_x, double *out_4747224507894995463) {
   out_4747224507894995463[0] = delta_x[0] + nom_x[0];
   out_4747224507894995463[1] = delta_x[1] + nom_x[1];
   out_4747224507894995463[2] = delta_x[2] + nom_x[2];
   out_4747224507894995463[3] = delta_x[3] + nom_x[3];
   out_4747224507894995463[4] = delta_x[4] + nom_x[4];
   out_4747224507894995463[5] = delta_x[5] + nom_x[5];
   out_4747224507894995463[6] = delta_x[6] + nom_x[6];
   out_4747224507894995463[7] = delta_x[7] + nom_x[7];
   out_4747224507894995463[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_2262248460398091275) {
   out_2262248460398091275[0] = -nom_x[0] + true_x[0];
   out_2262248460398091275[1] = -nom_x[1] + true_x[1];
   out_2262248460398091275[2] = -nom_x[2] + true_x[2];
   out_2262248460398091275[3] = -nom_x[3] + true_x[3];
   out_2262248460398091275[4] = -nom_x[4] + true_x[4];
   out_2262248460398091275[5] = -nom_x[5] + true_x[5];
   out_2262248460398091275[6] = -nom_x[6] + true_x[6];
   out_2262248460398091275[7] = -nom_x[7] + true_x[7];
   out_2262248460398091275[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_2474633098705929931) {
   out_2474633098705929931[0] = 1.0;
   out_2474633098705929931[1] = 0.0;
   out_2474633098705929931[2] = 0.0;
   out_2474633098705929931[3] = 0.0;
   out_2474633098705929931[4] = 0.0;
   out_2474633098705929931[5] = 0.0;
   out_2474633098705929931[6] = 0.0;
   out_2474633098705929931[7] = 0.0;
   out_2474633098705929931[8] = 0.0;
   out_2474633098705929931[9] = 0.0;
   out_2474633098705929931[10] = 1.0;
   out_2474633098705929931[11] = 0.0;
   out_2474633098705929931[12] = 0.0;
   out_2474633098705929931[13] = 0.0;
   out_2474633098705929931[14] = 0.0;
   out_2474633098705929931[15] = 0.0;
   out_2474633098705929931[16] = 0.0;
   out_2474633098705929931[17] = 0.0;
   out_2474633098705929931[18] = 0.0;
   out_2474633098705929931[19] = 0.0;
   out_2474633098705929931[20] = 1.0;
   out_2474633098705929931[21] = 0.0;
   out_2474633098705929931[22] = 0.0;
   out_2474633098705929931[23] = 0.0;
   out_2474633098705929931[24] = 0.0;
   out_2474633098705929931[25] = 0.0;
   out_2474633098705929931[26] = 0.0;
   out_2474633098705929931[27] = 0.0;
   out_2474633098705929931[28] = 0.0;
   out_2474633098705929931[29] = 0.0;
   out_2474633098705929931[30] = 1.0;
   out_2474633098705929931[31] = 0.0;
   out_2474633098705929931[32] = 0.0;
   out_2474633098705929931[33] = 0.0;
   out_2474633098705929931[34] = 0.0;
   out_2474633098705929931[35] = 0.0;
   out_2474633098705929931[36] = 0.0;
   out_2474633098705929931[37] = 0.0;
   out_2474633098705929931[38] = 0.0;
   out_2474633098705929931[39] = 0.0;
   out_2474633098705929931[40] = 1.0;
   out_2474633098705929931[41] = 0.0;
   out_2474633098705929931[42] = 0.0;
   out_2474633098705929931[43] = 0.0;
   out_2474633098705929931[44] = 0.0;
   out_2474633098705929931[45] = 0.0;
   out_2474633098705929931[46] = 0.0;
   out_2474633098705929931[47] = 0.0;
   out_2474633098705929931[48] = 0.0;
   out_2474633098705929931[49] = 0.0;
   out_2474633098705929931[50] = 1.0;
   out_2474633098705929931[51] = 0.0;
   out_2474633098705929931[52] = 0.0;
   out_2474633098705929931[53] = 0.0;
   out_2474633098705929931[54] = 0.0;
   out_2474633098705929931[55] = 0.0;
   out_2474633098705929931[56] = 0.0;
   out_2474633098705929931[57] = 0.0;
   out_2474633098705929931[58] = 0.0;
   out_2474633098705929931[59] = 0.0;
   out_2474633098705929931[60] = 1.0;
   out_2474633098705929931[61] = 0.0;
   out_2474633098705929931[62] = 0.0;
   out_2474633098705929931[63] = 0.0;
   out_2474633098705929931[64] = 0.0;
   out_2474633098705929931[65] = 0.0;
   out_2474633098705929931[66] = 0.0;
   out_2474633098705929931[67] = 0.0;
   out_2474633098705929931[68] = 0.0;
   out_2474633098705929931[69] = 0.0;
   out_2474633098705929931[70] = 1.0;
   out_2474633098705929931[71] = 0.0;
   out_2474633098705929931[72] = 0.0;
   out_2474633098705929931[73] = 0.0;
   out_2474633098705929931[74] = 0.0;
   out_2474633098705929931[75] = 0.0;
   out_2474633098705929931[76] = 0.0;
   out_2474633098705929931[77] = 0.0;
   out_2474633098705929931[78] = 0.0;
   out_2474633098705929931[79] = 0.0;
   out_2474633098705929931[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_1169872300789053017) {
   out_1169872300789053017[0] = state[0];
   out_1169872300789053017[1] = state[1];
   out_1169872300789053017[2] = state[2];
   out_1169872300789053017[3] = state[3];
   out_1169872300789053017[4] = state[4];
   out_1169872300789053017[5] = dt*(stiffness_front*(-state[2] - state[3] + state[7])*state[0]/state[1] + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/state[4] + ((-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/state[4] - state[4])*state[6] - 9.8100000000000005*state[8]) + state[5];
   out_1169872300789053017[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_1169872300789053017[7] = state[7];
   out_1169872300789053017[8] = state[8];
}
void F_fun(double *state, double dt, double *out_3775195569143089465) {
   out_3775195569143089465[0] = 1;
   out_3775195569143089465[1] = 0;
   out_3775195569143089465[2] = 0;
   out_3775195569143089465[3] = 0;
   out_3775195569143089465[4] = 0;
   out_3775195569143089465[5] = 0;
   out_3775195569143089465[6] = 0;
   out_3775195569143089465[7] = 0;
   out_3775195569143089465[8] = 0;
   out_3775195569143089465[9] = 0;
   out_3775195569143089465[10] = 1;
   out_3775195569143089465[11] = 0;
   out_3775195569143089465[12] = 0;
   out_3775195569143089465[13] = 0;
   out_3775195569143089465[14] = 0;
   out_3775195569143089465[15] = 0;
   out_3775195569143089465[16] = 0;
   out_3775195569143089465[17] = 0;
   out_3775195569143089465[18] = 0;
   out_3775195569143089465[19] = 0;
   out_3775195569143089465[20] = 1;
   out_3775195569143089465[21] = 0;
   out_3775195569143089465[22] = 0;
   out_3775195569143089465[23] = 0;
   out_3775195569143089465[24] = 0;
   out_3775195569143089465[25] = 0;
   out_3775195569143089465[26] = 0;
   out_3775195569143089465[27] = 0;
   out_3775195569143089465[28] = 0;
   out_3775195569143089465[29] = 0;
   out_3775195569143089465[30] = 1;
   out_3775195569143089465[31] = 0;
   out_3775195569143089465[32] = 0;
   out_3775195569143089465[33] = 0;
   out_3775195569143089465[34] = 0;
   out_3775195569143089465[35] = 0;
   out_3775195569143089465[36] = 0;
   out_3775195569143089465[37] = 0;
   out_3775195569143089465[38] = 0;
   out_3775195569143089465[39] = 0;
   out_3775195569143089465[40] = 1;
   out_3775195569143089465[41] = 0;
   out_3775195569143089465[42] = 0;
   out_3775195569143089465[43] = 0;
   out_3775195569143089465[44] = 0;
   out_3775195569143089465[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/state[1] + (-stiffness_front - stiffness_rear)*state[5]/state[4] + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/state[4]);
   out_3775195569143089465[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/pow(state[1], 2);
   out_3775195569143089465[47] = -dt*stiffness_front*state[0]/state[1];
   out_3775195569143089465[48] = -dt*stiffness_front*state[0]/state[1];
   out_3775195569143089465[49] = dt*(-(-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/pow(state[4], 2) + (-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/pow(state[4], 2) - 1)*state[6]);
   out_3775195569143089465[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/state[4] + 1;
   out_3775195569143089465[51] = dt*((-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/state[4] - state[4]);
   out_3775195569143089465[52] = dt*stiffness_front*state[0]/state[1];
   out_3775195569143089465[53] = -9.8100000000000005*dt;
   out_3775195569143089465[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_3775195569143089465[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_3775195569143089465[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_3775195569143089465[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_3775195569143089465[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_3775195569143089465[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_3775195569143089465[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_3775195569143089465[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_3775195569143089465[62] = 0;
   out_3775195569143089465[63] = 0;
   out_3775195569143089465[64] = 0;
   out_3775195569143089465[65] = 0;
   out_3775195569143089465[66] = 0;
   out_3775195569143089465[67] = 0;
   out_3775195569143089465[68] = 0;
   out_3775195569143089465[69] = 0;
   out_3775195569143089465[70] = 1;
   out_3775195569143089465[71] = 0;
   out_3775195569143089465[72] = 0;
   out_3775195569143089465[73] = 0;
   out_3775195569143089465[74] = 0;
   out_3775195569143089465[75] = 0;
   out_3775195569143089465[76] = 0;
   out_3775195569143089465[77] = 0;
   out_3775195569143089465[78] = 0;
   out_3775195569143089465[79] = 0;
   out_3775195569143089465[80] = 1;
}
void h_25(double *state, double *unused, double *out_8815782446792911046) {
   out_8815782446792911046[0] = state[6];
}
void H_25(double *state, double *unused, double *out_8050772942029761880) {
   out_8050772942029761880[0] = 0;
   out_8050772942029761880[1] = 0;
   out_8050772942029761880[2] = 0;
   out_8050772942029761880[3] = 0;
   out_8050772942029761880[4] = 0;
   out_8050772942029761880[5] = 0;
   out_8050772942029761880[6] = 1;
   out_8050772942029761880[7] = 0;
   out_8050772942029761880[8] = 0;
}
void h_24(double *state, double *unused, double *out_1015814972015559799) {
   out_1015814972015559799[0] = state[4];
   out_1015814972015559799[1] = state[5];
}
void H_24(double *state, double *unused, double *out_4492847343227438744) {
   out_4492847343227438744[0] = 0;
   out_4492847343227438744[1] = 0;
   out_4492847343227438744[2] = 0;
   out_4492847343227438744[3] = 0;
   out_4492847343227438744[4] = 1;
   out_4492847343227438744[5] = 0;
   out_4492847343227438744[6] = 0;
   out_4492847343227438744[7] = 0;
   out_4492847343227438744[8] = 0;
   out_4492847343227438744[9] = 0;
   out_4492847343227438744[10] = 0;
   out_4492847343227438744[11] = 0;
   out_4492847343227438744[12] = 0;
   out_4492847343227438744[13] = 0;
   out_4492847343227438744[14] = 1;
   out_4492847343227438744[15] = 0;
   out_4492847343227438744[16] = 0;
   out_4492847343227438744[17] = 0;
}
void h_30(double *state, double *unused, double *out_1749688976162591385) {
   out_1749688976162591385[0] = state[4];
}
void H_30(double *state, double *unused, double *out_5532439983522513253) {
   out_5532439983522513253[0] = 0;
   out_5532439983522513253[1] = 0;
   out_5532439983522513253[2] = 0;
   out_5532439983522513253[3] = 0;
   out_5532439983522513253[4] = 1;
   out_5532439983522513253[5] = 0;
   out_5532439983522513253[6] = 0;
   out_5532439983522513253[7] = 0;
   out_5532439983522513253[8] = 0;
}
void h_26(double *state, double *unused, double *out_3597782650638396725) {
   out_3597782650638396725[0] = state[7];
}
void H_26(double *state, double *unused, double *out_6654467812805733512) {
   out_6654467812805733512[0] = 0;
   out_6654467812805733512[1] = 0;
   out_6654467812805733512[2] = 0;
   out_6654467812805733512[3] = 0;
   out_6654467812805733512[4] = 0;
   out_6654467812805733512[5] = 0;
   out_6654467812805733512[6] = 0;
   out_6654467812805733512[7] = 1;
   out_6654467812805733512[8] = 0;
}
void h_27(double *state, double *unused, double *out_4629288359255794925) {
   out_4629288359255794925[0] = state[3];
}
void H_27(double *state, double *unused, double *out_3693511489751756627) {
   out_3693511489751756627[0] = 0;
   out_3693511489751756627[1] = 0;
   out_3693511489751756627[2] = 0;
   out_3693511489751756627[3] = 1;
   out_3693511489751756627[4] = 0;
   out_3693511489751756627[5] = 0;
   out_3693511489751756627[6] = 0;
   out_3693511489751756627[7] = 0;
   out_3693511489751756627[8] = 0;
}
void h_29(double *state, double *unused, double *out_4354094296971289036) {
   out_4354094296971289036[0] = state[1];
}
void H_29(double *state, double *unused, double *out_6378506145866573722) {
   out_6378506145866573722[0] = 0;
   out_6378506145866573722[1] = 1;
   out_6378506145866573722[2] = 0;
   out_6378506145866573722[3] = 0;
   out_6378506145866573722[4] = 0;
   out_6378506145866573722[5] = 0;
   out_6378506145866573722[6] = 0;
   out_6378506145866573722[7] = 0;
   out_6378506145866573722[8] = 0;
}
void h_28(double *state, double *unused, double *out_5572798212157457360) {
   out_5572798212157457360[0] = state[0];
}
void H_28(double *state, double *unused, double *out_8342136417431899973) {
   out_8342136417431899973[0] = 1;
   out_8342136417431899973[1] = 0;
   out_8342136417431899973[2] = 0;
   out_8342136417431899973[3] = 0;
   out_8342136417431899973[4] = 0;
   out_8342136417431899973[5] = 0;
   out_8342136417431899973[6] = 0;
   out_8342136417431899973[7] = 0;
   out_8342136417431899973[8] = 0;
}
void h_31(double *state, double *unused, double *out_1134300945652900578) {
   out_1134300945652900578[0] = state[8];
}
void H_31(double *state, double *unused, double *out_6028259710572382036) {
   out_6028259710572382036[0] = 0;
   out_6028259710572382036[1] = 0;
   out_6028259710572382036[2] = 0;
   out_6028259710572382036[3] = 0;
   out_6028259710572382036[4] = 0;
   out_6028259710572382036[5] = 0;
   out_6028259710572382036[6] = 0;
   out_6028259710572382036[7] = 0;
   out_6028259710572382036[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_4747224507894995463) {
  err_fun(nom_x, delta_x, out_4747224507894995463);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_2262248460398091275) {
  inv_err_fun(nom_x, true_x, out_2262248460398091275);
}
void car_H_mod_fun(double *state, double *out_2474633098705929931) {
  H_mod_fun(state, out_2474633098705929931);
}
void car_f_fun(double *state, double dt, double *out_1169872300789053017) {
  f_fun(state,  dt, out_1169872300789053017);
}
void car_F_fun(double *state, double dt, double *out_3775195569143089465) {
  F_fun(state,  dt, out_3775195569143089465);
}
void car_h_25(double *state, double *unused, double *out_8815782446792911046) {
  h_25(state, unused, out_8815782446792911046);
}
void car_H_25(double *state, double *unused, double *out_8050772942029761880) {
  H_25(state, unused, out_8050772942029761880);
}
void car_h_24(double *state, double *unused, double *out_1015814972015559799) {
  h_24(state, unused, out_1015814972015559799);
}
void car_H_24(double *state, double *unused, double *out_4492847343227438744) {
  H_24(state, unused, out_4492847343227438744);
}
void car_h_30(double *state, double *unused, double *out_1749688976162591385) {
  h_30(state, unused, out_1749688976162591385);
}
void car_H_30(double *state, double *unused, double *out_5532439983522513253) {
  H_30(state, unused, out_5532439983522513253);
}
void car_h_26(double *state, double *unused, double *out_3597782650638396725) {
  h_26(state, unused, out_3597782650638396725);
}
void car_H_26(double *state, double *unused, double *out_6654467812805733512) {
  H_26(state, unused, out_6654467812805733512);
}
void car_h_27(double *state, double *unused, double *out_4629288359255794925) {
  h_27(state, unused, out_4629288359255794925);
}
void car_H_27(double *state, double *unused, double *out_3693511489751756627) {
  H_27(state, unused, out_3693511489751756627);
}
void car_h_29(double *state, double *unused, double *out_4354094296971289036) {
  h_29(state, unused, out_4354094296971289036);
}
void car_H_29(double *state, double *unused, double *out_6378506145866573722) {
  H_29(state, unused, out_6378506145866573722);
}
void car_h_28(double *state, double *unused, double *out_5572798212157457360) {
  h_28(state, unused, out_5572798212157457360);
}
void car_H_28(double *state, double *unused, double *out_8342136417431899973) {
  H_28(state, unused, out_8342136417431899973);
}
void car_h_31(double *state, double *unused, double *out_1134300945652900578) {
  h_31(state, unused, out_1134300945652900578);
}
void car_H_31(double *state, double *unused, double *out_6028259710572382036) {
  H_31(state, unused, out_6028259710572382036);
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
