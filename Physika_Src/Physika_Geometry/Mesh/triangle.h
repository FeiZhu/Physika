/*
 * @file triangle.h 
 * @Basic triangle class.
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

#ifndef PHYSIKA_GEOMETRY_MESH_TRIANGLE_H_
#define PHYSIKA_GEOMETRY_MESH_TRIANGLE_H_

#include "Physika_Core/Utilities/type_define.h"

namespace Physika{

class Vertex;
class Edge;

class Triangle
{
public:
	Vertex *v[3];
	Edge *e[3];
	Vector3f normal;
	Vector3f center;
	float area;

};
} //end of namespace Physika

#endif //PHYSIKA_GEOMETRY_MESH_TRIANGLE_H_