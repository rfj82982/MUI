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
 * @file mui_2d.cpp
 * @author Stefano Rolfo
 * @date May 08th 2019
 * @brief C++ wrapper for C using 2D points
 *
 */

#include "../../mui.h"

extern "C" {

using namespace mui;

typedef uniface2d                        mui_uniface2d;
typedef sampler_gauss2d<double>          mui_sampler_gauss2d;
typedef sampler_moving_average2d<double> mui_sampler_moving_average2d;
typedef chrono_sampler_exact2d           mui_chrono_sampler_exact2d;
typedef chrono_sampler_mean2d            mui_chrono_sampler_mean2d;
typedef sampler_exact2d<double>            mui_sampler_exact2d;
typedef sampler_nearest_neighbor2d<double> mui_sampler_nearest2d;
typedef sampler_pseudo_nearest_neighbor2d<double> mui_sampler_pseudo_nearest_neighbor2d;
typedef sampler_pseudo_nearest2_linear2d<double> mui_sampler_pseudo_nearest2_linear2d;
typedef geometry::box2d mui_geometry_box2d;
typedef geometry::sphere2d mui_geometry_sphere2d;

// allocator
mui_uniface2d* mui_create_uniface2d( const char *URI ) {
	return new mui_uniface2d( URI );
}

mui_sampler_gauss2d* mui_create_sampler_2d( double r, double h ) {
	return new mui_sampler_gauss2d( r, h );
}

mui_sampler_moving_average2d* mui_create_sampler_moving_average2d( double dx, double dy  ) {
	return new mui_sampler_moving_average2d( point2d(dx,dy) );
}

mui_sampler_exact2d* mui_create_sampler_exact2d(void) {
    return new mui_sampler_exact2d();
}

mui_sampler_nearest2d* mui_create_sampler_nearest2d(void) {
    return new mui_sampler_nearest2d();
}

mui_sampler_pseudo_nearest_neighbor2d* mui_create_sampler_pseudo_nearest_neighbor2d( double h ) {
    return new mui_sampler_pseudo_nearest_neighbor2d( h );
}

mui_sampler_pseudo_nearest2_linear2d* mui_create_sampler_pseudo_nearest2_linear2d( double h ) {
    return new mui_sampler_pseudo_nearest2_linear2d( h );
}

mui_chrono_sampler_exact2d* mui_create_chrono_sampler_exact2d(void) {
	return new mui_chrono_sampler_exact2d;
}

mui_chrono_sampler_mean2d* mui_create_chrono_sampler_mean2d( double past, double future ) {
	return new mui_chrono_sampler_mean2d( past, future );
}

mui_geometry_box2d* mui_create_geometry_box2d(double l1_x, double l1_y, double l2_x, double l2_y){
	return new mui_geometry_box2d(point2d(l1_x,l1_y),point2d(l2_x,l2_y));
}

mui_geometry_sphere2d* mui_create_geometry_sphere2d(double l1_x, double l1_y, double rr){
	return new mui_geometry_sphere2d(point2d(l1_x,l1_y),rr);
}

// deallocator
void mui_destroy_uniface2d( mui_uniface2d *uniface ) {
	delete uniface;
}

void mui_destroy_sampler_2d( mui_sampler_gauss2d* sampler ) {
	delete sampler;
}

void mui_destroy_sampler_moving_average2d( mui_sampler_moving_average2d* sampler ) {
	delete sampler;
}
void mui_destroy_sampler_nearest2d( mui_sampler_nearest2d* sampler ) {
	delete sampler;
}

void mui_destroy_sampler_pseudo_nearest_neighbor2d( mui_sampler_pseudo_nearest_neighbor2d* sampler ) {
	delete sampler;
}

void mui_destroy_sampler_pseudo_nearest2_linear2d( mui_sampler_pseudo_nearest2_linear2d* sampler ) {
	delete sampler;
}

void mui_destroy_chrono_sampler_exact2d( mui_chrono_sampler_exact2d* sampler ) {
	delete sampler;
}

void mui_destroy_chrono_sampler_mean2d( mui_chrono_sampler_mean2d* sampler ) {
	delete sampler;
}

void mui_destroy_geometry_box2d( mui_geometry_box2d* box2d){
	delete box2d;
}

void mui_destroy_geometry_sphere2d( mui_geometry_sphere2d* sphere2d){
	delete sphere2d;
}

// push
void mui_push( mui_uniface2d* uniface, const char *attr, double x, double y , double value ) {
	uniface->push( std::string(attr), point2d(x,y), value );
}

// spatial sampler: gaussian
// temporal sampler: exact point
double mui_fetch_gaussian_exact( mui_uniface2d* uniface, const char *attr, double x, double y , double t, mui_sampler_gauss2d *spatial, mui_chrono_sampler_exact2d *temporal ) {
	return uniface->fetch( std::string(attr), point2d(x,y), t, *spatial, *temporal );
}
// spatial sampler: exact
// temporal sampler: exact point
double mui_fetch_exact_exact( mui_uniface2d* uniface, const char *attr, double x, double y , double t, mui_sampler_exact2d *spatial, mui_chrono_sampler_exact2d *temporal ) {
	return uniface->fetch( std::string(attr), point2d(x,y), t, *spatial, *temporal );
}

// spatial sampler: nearest
// temporal sampler: exact point
double mui_fetch_nearest_exact( mui_uniface2d* uniface, const char *attr, double x, double y , double t, mui_sampler_nearest2d *spatial, mui_chrono_sampler_exact2d *temporal ) {
	return uniface->fetch( std::string(attr), point2d(x,y), t, *spatial, *temporal );
}

// spatial sampler: pseudo nearest
// temporal sampler: exact point
double mui_fetch_pseudo_nearest_exact( mui_uniface2d* uniface, const char *attr, double x, double y , double t, mui_sampler_pseudo_nearest_neighbor2d *spatial, mui_chrono_sampler_exact2d *temporal ) {
	return uniface->fetch( std::string(attr), point2d(x,y), t, *spatial, *temporal );
}

// spatial sampler: pseudo nearest2 linear
// temporal sampler: exact point
double mui_fetch_pseudo_nearest2_linear_exact( mui_uniface2d* uniface, const char *attr, double x, double y , double t, mui_sampler_pseudo_nearest2_linear2d *spatial, mui_chrono_sampler_exact2d *temporal ) {
	return uniface->fetch( std::string(attr), point2d(x,y), t, *spatial, *temporal );
}

// spatial sampler: gaussian
// temporal sampler: mean
double mui_fetch_gaussian_mean( mui_uniface2d* uniface, const char *attr, double x, double y , double t, mui_sampler_gauss2d *spatial, mui_chrono_sampler_mean2d *temporal ) {
	return uniface->fetch( std::string(attr), point2d(x,y), t, *spatial, *temporal );
}

// spatial sampler: moving average
// temporal sampler: exact point
double mui_fetch_moving_average_exact( mui_uniface2d* uniface, const char *attr, double x, double y , double t, mui_sampler_moving_average2d *spatial, mui_chrono_sampler_exact2d *temporal ) {
	return uniface->fetch( std::string(attr), point2d(x,y), t, *spatial, *temporal );
}

// spatial sampler: moving_average
// temporal sampler: mean
double mui_fetch_moving_average_mean( mui_uniface2d* uniface, const char *attr, double x, double y , double t, mui_sampler_moving_average2d *spatial, mui_chrono_sampler_mean2d *temporal ) {
	return uniface->fetch( std::string(attr), point2d(x,y), t, *spatial, *temporal );
}

// announce send/receive using different geometries
void mui_announce_send_span_box(mui_uniface2d* uniface, double t0, double tfin, mui_geometry_box2d *box2d){
	uniface->announce_send_span( t0, tfin , *box2d );
}

void mui_announce_recv_span_box(mui_uniface2d* uniface, double t0, double tfin, mui_geometry_box2d *box2d){
	uniface->announce_recv_span( t0, tfin , *box2d );
}

void mui_announce_send_span_sphere(mui_uniface2d* uniface, double t0, double tfin, mui_geometry_sphere2d *sphere2d){
	uniface->announce_send_span( t0, tfin , *sphere2d );
}

void mui_announce_recv_span_sphere(mui_uniface2d* uniface, double t0, double tfin, mui_geometry_sphere2d *sphere2d){
	uniface->announce_recv_span( t0, tfin , *sphere2d );
}

// commit all data in buffer
void mui_commit( mui_uniface2d* uniface, double t ) {
	uniface->commit( t );
}

// commit all data in buffer and return number of communication
int mui_commit_ranks( mui_uniface2d* uniface, double t ) {
	return uniface->commit( t );
}

// wait for peers
void mui_barrier( mui_uniface2d* uniface, double t ) {
	uniface->barrier( t );
}

// remove obsolete data
void mui_forget( mui_uniface2d* uniface, double first, double last ) {
	uniface->forget( first, last );
}

// set automatic deletion
void mui_set_memory( mui_uniface2d* uniface, double length ) {
	return uniface->set_memory( length );
}

// send a double
void mui_send_double( mui_uniface2d* uniface, const char *attr, double value ) {
        uniface->push( std::string(attr), value );
}

// fetch a double
double mui_fetch_double( mui_uniface2d* uniface, const char *attr ) {
        return uniface->fetch<double>( std::string(attr) );
}

// assign int
void mui_send_int( mui_uniface2d* uniface, const char *attr, int value ) {
        uniface->push( std::string(attr), value );
}

// fetch assigned
int mui_fetch_int( mui_uniface2d* uniface, const char *attr ) {
        return uniface->fetch<int>( std::string(attr) );
}

// split comm
MPI_Comm mui_mpi_split_by_app(void) {
    return mpi_split_by_app();
}

}
