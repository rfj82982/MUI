/*****************************************************************************
* Multiscale Universal Interface Code Coupling Library Demo 6                *
*                                                                            *
* Copyright (C) 2017 Y. H. Tang, S. Kudo, X. Bian, Z. Li, G. E. Karniadakis  *
* Copyright (C) 2019 S. Rolfo (*STFC Daresbury laboratory)                   *
*                                                                            *
* This software is jointly licensed under the Apache License, Version 2.0    *
* and the GNU General Public License version 3, you may use it according     *
* to either.                                                                 *
*                                                                            *
* ** Apache License, version 2.0 **                                          *
*                                                                            *
* Licensed under the Apache License, Version 2.0 (the "License");            *
* you may not use this file except in compliance with the License.           *
* You may obtain a copy of the License at                                    *
*                                                                            *
* http://www.apache.org/licenses/LICENSE-2.0                                 *
*                                                                            *
* Unless required by applicable law or agreed to in writing, software        *
* distributed under the License is distributed on an "AS IS" BASIS,          *
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.   *
* See the License for the specific language governing permissions and        *
* limitations under the License.                                             *
*                                                                            *
* ** GNU General Public License, version 3 **                                *
*                                                                            *
* This program is free software: you can redistribute it and/or modify       *
* it under the terms of the GNU General Public License as published by       *
* the Free Software Foundation, either version 3 of the License, or          *
* (at your option) any later version.                                        *
*                                                                            *
* This program is distributed in the hope that it will be useful,            *
* but WITHOUT ANY WARRANTY; without even the implied warranty of             *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              *
* GNU General Public License for more details.                               *
*                                                                            *
* You should have received a copy of the GNU General Public License          *
* along with this program.  If not, see <http://www.gnu.org/licenses/>.      *
******************************************************************************/

/**
 * @file mui_2d.h
 * @author Stefano Rolfo
 * @date May 08th 2019
 * @brief C include for 2D points
 *
 */

#ifndef MUI_2D_H_
#define MUI_2D_H_

#include "mpi.h"

typedef struct mui_uniface2d                          mui_uniface2d;
typedef struct mui_sampler_gauss2d                    mui_sampler_gauss2d;
typedef struct mui_sampler_moving_average2d           mui_sampler_moving_average2d;
typedef struct mui_chrono_sampler_exact2d             mui_chrono_sampler_exact2d;
typedef struct mui_chrono_sampler_mean2d              mui_chrono_sampler_mean2d;
typedef struct mui_sampler_exact2d                    mui_sampler_exact2d;
typedef struct mui_sampler_nearest2d                  mui_sampler_nearest2d;
typedef struct mui_sampler_pseudo_nearest_neighbor2d  mui_sampler_pseudo_nearest_neighbor2d;
typedef struct mui_sampler_pseudo_nearest2_linear2d   mui_sampler_pseudo_nearest2_linear2d;
typedef struct mui_geometry_box2d                     mui_geometry_box2d;
typedef struct mui_geometry_sphere2d                  mui_geometry_sphere2d;


/* allocator */
mui_uniface2d* mui_create_uniface2d( const char *URI );
mui_sampler_gauss2d* mui_create_sampler_2d( double r, double h );
mui_sampler_moving_average2d* mui_create_sampler_moving_average2d( double dx, double dy );
mui_sampler_exact2d* mui_create_sampler_exact2d();
mui_sampler_nearest2d* mui_create_sampler_nearest2d();
mui_sampler_pseudo_nearest_neighbor2d* mui_create_sampler_pseudo_nearest_neighbor2d();
mui_sampler_pseudo_nearest2_linear2d* mui_create_sampler_pseudo_nearest2_linear2d();

mui_chrono_sampler_exact2d* mui_create_chrono_sampler_exact2d();
mui_chrono_sampler_mean2d* mui_create_chrono_sampler_mean2d( double past, double future );

mui_geometry_box2d* mui_create_geometry_box2d(double l1_x, double l1_y, double l2_x, double l2_y);
mui_geometry_sphere2d* mui_create_geometry_sphere2d(double l1_x, double l1_y, double rr );

/* deallocator */
void mui_destroy_uniface2d( mui_uniface2d *uniface );
void mui_destroy_sampler_2d( mui_sampler_gauss2d* sampler );
void mui_destroy_sampler_moving_average2d( mui_sampler_moving_average2d* sampler );
void mui_destroy_sampler_exact2d( mui_sampler_exact2d* sampler );
void mui_destroy_sampler_nearest2d( mui_sampler_nearest2d* sampler );
void mui_destroy_sampler_pseudo_nearest_neighbor2d( mui_sampler_pseudo_nearest_neighbor2d* sampler );
void mui_destroy_sampler_nearest2_linear2d( mui_sampler_pseudo_nearest2_linear2d* sampler );

void mui_destroy_chrono_sampler_exact2d( mui_chrono_sampler_exact2d* sampler );
void mui_destroy_chrono_sampler_mean2d( mui_chrono_sampler_mean2d* sampler );

void mui_destroy_geometry_box2d( mui_geometry_box2d* box2d);
void mui_destroy_geometry_sphere2d( mui_geometry_sphere2d* sphere2d);

/* push */
void mui_push( mui_uniface2d* uniface, const char *attr, double x, double y, double t );

/*  spatial sampler: gaussian */
/*  temporal sampler: exact point */
double mui_fetch_gaussian_exact( mui_uniface2d* uniface, const char *attr, double x, double y, double t, mui_sampler_gauss2d *spatial, mui_chrono_sampler_exact2d *temporal );

/*  spatial sampler: exact */
/*  temporal sampler: exact point */
double mui_fetch_exact_exact( mui_uniface2d* uniface, const char *attr, double x, double y, double t, mui_sampler_exact2d *spatial, mui_chrono_sampler_exact2d *temporal );

/*  spatial sampler: nearest */
/*  temporal sampler: exact point */
double mui_fetch_nearest_exact( mui_uniface2d* uniface, const char *attr, double x, double y, double t, mui_sampler_nearest2d *spatial, mui_chrono_sampler_exact2d *temporal );


/*  spatial sampler: pseudo nearest */
/*  temporal sampler: exact point */
double mui_fetch_pseudo_nearest_exact( mui_uniface2d* uniface, const char *attr, double x, double y, double t, mui_sampler_pseudo_nearest_neighbor2d *spatial, mui_chrono_sampler_exact2d *temporal );


/*  spatial sampler: pseudo nearest2 linear */
/*  temporal sampler: exact point */
double mui_fetch_pseudo_nearest2_linear_exact( mui_uniface2d* uniface, const char *attr, double x, double y, double t, mui_sampler_pseudo_nearest2_linear2d *spatial, mui_chrono_sampler_exact2d *temporal );


/*  spatial sampler: gaussian */
/*  temporal sampler: mean */
double mui_fetch_gaussian_mean( mui_uniface2d* uniface, const char *attr, double x, double y, double t, mui_sampler_gauss2d *spatial, mui_chrono_sampler_mean2d *temporal );

/*  spatial sampler: moving average */
/*  temporal sampler: exact point */
double mui_fetch_moving_average_exact( mui_uniface2d* uniface, const char *attr, double x, double y, double t, mui_sampler_moving_average2d *spatial, mui_chrono_sampler_exact2d *temporal );

/*  spatial sampler: moving_average */
/*  temporal sampler: mean */
double mui_fetch_moving_average_mean( mui_uniface2d* uniface, const char *attr, double x, double y, double z, double t, mui_sampler_moving_average2d *spatial, mui_chrono_sampler_mean2d *temporal );

/*  Connection between instances using different geomtries */
/*  Announce Send Box */
void mui_announce_send_span_box(mui_uniface2d* uniface, double t0, double tfin, mui_geometry_box2d *box2d);

/*  Announce Receive Box */
void mui_announce_recv_span_box(mui_uniface2d* uniface, double t0, double tfin, mui_geometry_box2d *box2d);

/*  Announce Send Sphere */
void mui_announce_send_span_sphere(mui_uniface2d* uniface, double t0, double tfin, mui_geometry_sphere2d *sphere2d);

/*  Announce Receive */
void mui_announce_recv_span_sphere(mui_uniface2d* uniface, double t0, double tfin, mui_geometry_box2d *box2d);

/*  commit all data in buffer */
void mui_commit( mui_uniface2d*, double t );

/*  commit all data in buffer and return the number of rank in the communication */
int mui_commit_ranks( mui_uniface2d*, double t );

/*  wait for peers */
void mui_barrier( mui_uniface2d*, double t );

/*  remove obsolete data */
void mui_forget( mui_uniface2d*, double first, double last );

/*  set automatic deletion */
void mui_set_memory( mui_uniface2d*, double length );

// send double
void mui_send_double( mui_uniface2d* uniface, const char *attr, double value );

// fetch double
double mui_fetch_double( mui_uniface2d* uniface, const char *attr );

// send int
void mui_send_int( mui_uniface2d* uniface, const char *attr, int value );

// fetch int
int mui_fetch_int( mui_uniface2d* uniface, const char *attr); 

/*  split comm */
MPI_Comm mui_mpi_split_by_app(void);

#endif /* MUI_2D_H_ */
