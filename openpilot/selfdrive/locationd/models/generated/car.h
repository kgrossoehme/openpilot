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
void car_err_fun(double *nom_x, double *delta_x, double *out_2427570131299459704);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_122641313029076524);
void car_H_mod_fun(double *state, double *out_7941775136222393929);
void car_f_fun(double *state, double dt, double *out_6974798855676325195);
void car_F_fun(double *state, double dt, double *out_1556117237806562757);
void car_h_25(double *state, double *unused, double *out_2762423067770022742);
void car_H_25(double *state, double *unused, double *out_5601277112302492847);
void car_h_24(double *state, double *unused, double *out_1315832138671900521);
void car_H_24(double *state, double *unused, double *out_3424062688695342874);
void car_h_30(double *state, double *unused, double *out_7921055749118856433);
void car_H_30(double *state, double *unused, double *out_3082944153795244220);
void car_h_26(double *state, double *unused, double *out_1543719152583854418);
void car_H_26(double *state, double *unused, double *out_9103963642533002545);
void car_h_27(double *state, double *unused, double *out_8681558302146463095);
void car_H_27(double *state, double *unused, double *out_859350082611301003);
void car_h_29(double *state, double *unused, double *out_5524015056929849538);
void car_H_29(double *state, double *unused, double *out_2572712809480852036);
void car_h_28(double *state, double *unused, double *out_443627665315179562);
void car_H_28(double *state, double *unused, double *out_7655111826550382610);
void car_h_31(double *state, double *unused, double *out_7803048355185479689);
void car_H_31(double *state, double *unused, double *out_5570631150425532419);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}