/*
 * @file type_define.h 
 * @brief This file is used to define the other name mainly for template class.
 * @author Sheng Yang
 * 
 * This file is part of Physika, a versatile physics simulation library.
 * Copyright (C) 2013 Physika Group.
 *
 * This Source Code Form is subject to the terms of the GNU General Public License v2.0. 
 * If a copy of the GPL was not distributed with this file, you can obtain one at:
 * http://www.gnu.org/licenses/gpl-2.0.html
 *
 */

#ifndef PHYSIKA_CORE_UTILITIES_TYPE_DEFINE_H_
#define PHYSIKA_CORE_UTILITIES_TYPE_DEFINE_H_

#include "Physika_Core/Vectors/vector_2d.h"
#include "Physika_Core/Vectors/vector_3d.h"
#include "Physika_Core/Matrices/matrix_2x2.h"
#include "Physika_Core/Matrices/matrix_3x3.h"

namespace Physika{

typedef Vector2D<float> Vector2f;
typedef Vector2D<double> Vector2d;

typedef Vector3D<float> Vector3f;
typedef Vector3D<double> Vector3d;

typedef Matrix2x2<float> Matrix2f;
typedef Matrix2x2<double> Matrix2d;

typedef Matrix3x3<float> Matrix3f;
typedef Matrix3x3<double> Matrix3d;

}

#endif //PHYSIKA_CORE_UTILITIES_TYPE_DEFINE_H_
