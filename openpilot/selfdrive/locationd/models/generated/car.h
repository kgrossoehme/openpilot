#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_4747224507894995463);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_2262248460398091275);
void car_H_mod_fun(double *state, double *out_2474633098705929931);
void car_f_fun(double *state, double dt, double *out_1169872300789053017);
void car_F_fun(double *state, double dt, double *out_3775195569143089465);
void car_h_25(double *state, double *unused, double *out_8815782446792911046);
void car_H_25(double *state, double *unused, double *out_8050772942029761880);
void car_h_24(double *state, double *unused, double *out_1015814972015559799);
void car_H_24(double *state, double *unused, double *out_4492847343227438744);
void car_h_30(double *state, double *unused, double *out_1749688976162591385);
void car_H_30(double *state, double *unused, double *out_5532439983522513253);
void car_h_26(double *state, double *unused, double *out_3597782650638396725);
void car_H_26(double *state, double *unused, double *out_6654467812805733512);
void car_h_27(double *state, double *unused, double *out_4629288359255794925);
void car_H_27(double *state, double *unused, double *out_3693511489751756627);
void car_h_29(double *state, double *unused, double *out_4354094296971289036);
void car_H_29(double *state, double *unused, double *out_6378506145866573722);
void car_h_28(double *state, double *unused, double *out_5572798212157457360);
void car_H_28(double *state, double *unused, double *out_8342136417431899973);
void car_h_31(double *state, double *unused, double *out_1134300945652900578);
void car_H_31(double *state, double *unused, double *out_6028259710572382036);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}