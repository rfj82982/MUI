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
 * @file mui_1d.cpp
 * @author Stefano Rolfo
 * @date May 08th 2019
 * @brief C++ wrapper for C using 1d points
 *
 */

#include "../../mui.h"

extern "C" {

using namespace mui;

typedef uniface1d                        mui_uniface1d;
typedef sampler_gauss1d<double>          mui_sampler_gauss1d;
typedef sampler_moving_average1d<double> mui_sampler_moving_average1d;
typedef chrono_sampler_exact1d           mui_chrono_sampler_exact1d;
typedef chrono_sampler_mean1d            mui_chrono_sampler_mean1d;
typedef sampler_exact1d<double>            mui_sampler_exact1d;
typedef sampler_nearest_neighbor1d<double> mui_sampler_nearest1d;
typedef sampler_pseudo_nearest_neighbor1d<double> mui_sampler_pseudo_nearest_neighbor1d;
typedef sampler_pseudo_nearest2_linear1d<double> mui_sampler_pseudo_nearest2_linear1d;
typedef geometry::box1d mui_geometry_box1d;

// allocator
mui_uniface1d* mui_create_uniface1d( const char *URI ) {
	return new mui_uniface1d( URI );
}

mui_sampler_gauss1d* mui_create_sampler_1d( double r, double h ) {
	return new mui_sampler_gauss1d( r, h );
}

mui_sampler_moving_average1d* mui_create_sampler_moving_average1d( double dx ) {
	return new mui_sampler_moving_average1d( point1d(dx) );
}

mui_sampler_exact1d* mui_create_sampler_exact1d() {
    return new mui_sampler_exact1d();
}

mui_sampler_nearest1d* mui_create_sampler_nearest1d() {
    return new mui_sampler_nearest1d();
}

mui_sampler_pseudo_nearest_neighbor1d* mui_create_sampler_pseudo_nearest_neighbor1d( double h ) {
    return new mui_sampler_pseudo_nearest_neighbor1d( h );
}

mui_sampler_pseudo_nearest2_linear1d* mui_create_sampler_pseudo_nearest2_linear1d( double h ) {
    return new mui_sampler_pseudo_nearest2_linear1d( h );
}

mui_chrono_sampler_exact1d* mui_create_chrono_sampler_exact1d() {
	return new mui_chrono_sampler_exact1d;
}

mui_chrono_sampler_mean1d* mui_create_chrono_sampler_mean1d( double past, double future ) {
	return new mui_chrono_sampler_mean1d( past, future );
}

mui_geometry_box1d* mui_create_geometry_box1d(double l1_x, double l2_x){
	return new mui_geometry_box1d(point1d(l1_x),point1d(l2_x));
}

// deallocator
void mui_destroy_uniface1d( mui_uniface1d *uniface ) {
	delete uniface;
}

void mui_destroy_sampler_1d( mui_sampler_gauss1d* sampler ) {
	delete sampler;
}

void mui_destroy_sampler_moving_average1d( mui_sampler_moving_average1d* sampler ) {
	delete sampler;
}
void mui_destroy_sampler_nearest1d( mui_sampler_nearest1d* sampler ) {
	delete sampler;
}

void mui_destroy_sampler_pseudo_nearest_neighbor1d( mui_sampler_pseudo_nearest_neighbor1d* sampler ) {
	delete sampler;
}

void mui_destroy_sampler_pseudo_nearest2_linear1d( mui_sampler_pseudo_nearest2_linear1d* sampler ) {
	delete sampler;
}

void mui_destroy_chrono_sampler_exact1d( mui_chrono_sampler_exact1d* sampler ) {
	delete sampler;
}

void mui_destroy_chrono_sampler_mean1d( mui_chrono_sampler_mean1d* sampler ) {
	delete sampler;
}

void mui_destroy_geometry_box1d( mui_geometry_box1d* box1d){
	delete box1d;
}

// push
void mui_push( mui_uniface1d* uniface, const char *attr, double x, double value ) {
	uniface->push( std::string(attr), point1d(x), value );
}

// spatial sampler: gaussian
// temporal sampler: exact point
double mui_fetch_gaussian_exact( mui_uniface1d* uniface, const char *attr, double x, double t, mui_sampler_gauss1d *spatial, mui_chrono_sampler_exact1d *temporal ) {
	return uniface->fetch( std::string(attr), point1d(x), t, *spatial, *temporal );
}
// spatial sampler: exact
// temporal sampler: exact point
double mui_fetch_exact_exact( mui_uniface1d* uniface, const char *attr, double x, double t, mui_sampler_exact1d *spatial, mui_chrono_sampler_exact1d *temporal ) {
	return uniface->fetch( std::string(attr), point1d(x), t, *spatial, *temporal );
}

// spatial sampler: nearest
// temporal sampler: exact point
double mui_fetch_nearest_exact( mui_uniface1d* uniface, const char *attr, double x, double t, mui_sampler_nearest1d *spatial, mui_chrono_sampler_exact1d *temporal ) {
	return uniface->fetch( std::string(attr), point1d(x), t, *spatial, *temporal );
}

// spatial sampler: pseudo nearest
// temporal sampler: exact point
double mui_fetch_pseudo_nearest_exact( mui_uniface1d* uniface, const char *attr, double x, double t, mui_sampler_pseudo_nearest_neighbor1d *spatial, mui_chrono_sampler_exact1d *temporal ) {
	return uniface->fetch( std::string(attr), point1d(x), t, *spatial, *temporal );
}

// spatial sampler: pseudo nearest2 linear
// temporal sampler: exact point
double mui_fetch_pseudo_nearest2_linear_exact( mui_uniface1d* uniface, const char *attr, double x, double t, mui_sampler_pseudo_nearest2_linear1d *spatial, mui_chrono_sampler_exact1d *temporal ) {
	return uniface->fetch( std::string(attr), point1d(x), t, *spatial, *temporal );
}

// spatial sampler: gaussian
// temporal sampler: mean
double mui_fetch_gaussian_mean( mui_uniface1d* uniface, const char *attr, double x, double t, mui_sampler_gauss1d *spatial, mui_chrono_sampler_mean1d *temporal ) {
	return uniface->fetch( std::string(attr), point1d(x), t, *spatial, *temporal );
}

// spatial sampler: moving average
// temporal sampler: exact point
double mui_fetch_moving_average_exact( mui_uniface1d* uniface, const char *attr, double x, double t, mui_sampler_moving_average1d *spatial, mui_chrono_sampler_exact1d *temporal ) {
	return uniface->fetch( std::string(attr), point1d(x), t, *spatial, *temporal );
}

// spatial sampler: moving_average
// temporal sampler: mean
double mui_fetch_moving_average_mean( mui_uniface1d* uniface, const char *attr, double x, double t, mui_sampler_moving_average1d *spatial, mui_chrono_sampler_mean1d *temporal ) {
	return uniface->fetch( std::string(attr), point1d(x), t, *spatial, *temporal );
}

void mui_announce_send_span(mui_uniface1d* uniface, double t0, double tfin, mui_geometry_box1d *box1d){
	uniface->announce_send_span( t0, tfin , *box1d );
}

void mui_announce_recv_span(mui_uniface1d* uniface, double t0, double tfin, mui_geometry_box1d *box1d){
	uniface->announce_recv_span( t0, tfin , *box1d );
}

// commit all data in buffer
void mui_commit( mui_uniface1d* uniface, double t ) {
	uniface->commit( t );
}

// wait for peers
void mui_barrier( mui_uniface1d* uniface, double t ) {
	uniface->barrier( t );
}

// remove obsolete data
void mui_forget( mui_uniface1d* uniface, double first, double last ) {
	uniface->forget( first, last );
}

// set automatic deletion
void mui_set_memory( mui_uniface1d* uniface, double length ) {
	return uniface->set_memory( length );
}

// send a double
void mui_send_double( mui_uniface1d* uniface, const char *attr, double value ) {
        uniface->push( std::string(attr), value );
}

// fetch a double
double mui_fetch_double( mui_uniface1d* uniface, const char *attr ) {
        return uniface->fetch<double>( std::string(attr) );
}

// assign int
void mui_send_int( mui_uniface1d* uniface, const char *attr, int value ) {
        uniface->push( std::string(attr), value );
}

// fetch assigned
int mui_fetch_int( mui_uniface1d* uniface, const char *attr ) {
        return uniface->fetch<int>( std::string(attr) );
}

// split comm
MPI_Comm mui_mpi_split_by_app() {
    return mpi_split_by_app();
}

}
