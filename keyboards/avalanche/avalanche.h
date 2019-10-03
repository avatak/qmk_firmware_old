/* Copyright 2019 avatak
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#include "quantum.h"

/* This a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT(\
    l00, l01, l02, l03, l04, l05,               r00, r01, r02, r03, r04, r05,\
    l10, l11, l12, l13, l14, l15,               r10, r11, r12, r13, r14, r15,\
    l20, l21, l22, l23, l24, l25,               r20, r21, r22, r23, r24, r25,\
    l30, l31, l32, l33, l34, l35,               r30, r31, r32, r33, r34, r35,\
    l40, l41, l42, l43, l44,                         r41, r42, r43, r44, r45,\
                             l45,               r40\
    ) \
    { \
    { l00, l01, l02, l03, l04, l05 },\
    { l10, l11, l12, l13, l14, l15 },\
    { l20, l21, l22, l23, l24, l25 },\
    { l30, l31, l32, l33, l34, l35 },\
    { l40, l41, l42, l43, l44, l45 },\
    { r00, r01, r02, r03, r04, r05 },\
    { r10, r11, r12, r13, r14, r15 },\
    { r20, r21, r22, r23, r24, r25 },\
    { r30, r31, r32, r33, r34, r35 },\
    { r40, r41, r42, r43, r44, r45 },\
    }

#define LAYOUT_kc( \
    l00, l01, l02, l03, l04, l05,               r00, r01, r02, r03, r04, r05,\
    l10, l11, l12, l13, l14, l15,               r10, r11, r12, r13, r14, r15,\
    l20, l21, l22, l23, l24, l25,               r20, r21, r22, r23, r24, r25,\
    l30, l31, l32, l33, l34, l35,               r30, r31, r32, r33, r34, r35,\
    l40, l41, l42, l43, l44,                         r41, r42, r43, r44, r45,\
                             l45,               r40\
    ) \
    { \
    { KC_##l00, KC_##l01, KC_##l02, KC_##l03, KC_##l04, KC_##l05 },\
    { KC_##l10, KC_##l11, KC_##l12, KC_##l13, KC_##l14, KC_##l15 },\
    { KC_##l20, KC_##l21, KC_##l22, KC_##l23, KC_##l24, KC_##l25 },\
    { KC_##l30, KC_##l31, KC_##l32, KC_##l33, KC_##l34, KC_##l35 },\
    { KC_##l40, KC_##l41, KC_##l42, KC_##l43, KC_##l44, KC_##l45 },\
    { KC_##r00, KC_##r01, KC_##r02, KC_##r03, KC_##r04, KC_##r05 },\
    { KC_##r10, KC_##r11, KC_##r12, KC_##r13, KC_##r14, KC_##r15 },\
    { KC_##r20, KC_##r21, KC_##r22, KC_##r23, KC_##r24, KC_##r25 },\
    { KC_##r30, KC_##r31, KC_##r32, KC_##r33, KC_##r34, KC_##r35 },\
    { KC_##r40, KC_##r41, KC_##r42, KC_##r43, KC_##r44, KC_##r45 },\
    }
