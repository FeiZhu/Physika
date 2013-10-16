/*
 * @file edge.h 
 * @Basic edge class.
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

#ifndef PHYSIKA_GEOMETRY_MESH_EDGE_H_
#define PHYSIKA_GEOMETRY_MESH_EDGE_H_

#include "Physika_Core/Utilities/type_define.h"

namespace Physika{

class Vertex;
class Triangle;

class Edge
{
public:
	Vertex *v[2];
	Triangle *t[2];
	Vector3f normal;

protected:
};
} //end of namespace Physika

#endif //PHYSIKA_GEOMETRY_MESH_EDGE_H_