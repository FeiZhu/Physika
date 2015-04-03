/*
 * @file color_bar.cpp
 * @Brief a color bar class for OpenGL.
 * @author Wei Chen
 * 
 * This file is part of Physika, a versatile physics simulation library.
 * Copyright (C) 2013 Physika Group.
 *
 * This Source Code Form is subject to the terms of the GNU General Public License v2.0. 
 * If a copy of the GPL was not distributed with this file, you can obtain one at:
 * http://www.gnu.org/licenses/gpl-2.0.html
 *
 */

#include "Physika_Render/ColorBar/color_bar.h"

namespace Physika{

template <typename Scalar>
ColorBar<Scalar>::ColorBar()
    :x_len_(3.0),y_len_(30.0),z_len_(2.0),start_point_(0)
{

}

template <typename Scalar>
ColorBar<Scalar>::~ColorBar()
{

}

template <typename Scalar>
const Vector<Scalar, 3> & ColorBar<Scalar>::startPoint() const
{
    return this->start_point_;
}

template <typename Scalar>
Scalar ColorBar<Scalar>::xLength() const
{
    return this->x_len_;
}

template <typename Scalar>
Scalar ColorBar<Scalar>::yLength() const
{
    return this->y_len_;
}

template <typename Scalar>
Scalar ColorBar<Scalar>::zLength() const
{
    return this->z_len_;
}

template <typename Scalar>
const ColorMap<Scalar> & ColorBar<Scalar>::colorMap() const
{
    return this->color_map_;
}

template <typename Scalar>
void ColorBar<Scalar>::setColorMap(const ColorMap<Scalar> & color_map)
{
    this->color_map_ = color_map_;
}

template <typename Scalar>
void ColorBar<Scalar>::setColorMapSize(unsigned int color_size)
{
    this->color_map_.setColorMapSize(color_size);
}

template <typename Scalar>
void ColorBar<Scalar>::setColorMapType(ColorMapType color_map_type)
{
    this->color_map_.setColorMapType(color_map_type);
}

template <typename Scalar>
void ColorBar<Scalar>::setColorMapTypeAndSize(ColorMapType color_map_type, unsigned int color_size)
{
    this->color_map_.setColorMapTypeAndSize(color_map_type, color_size);
}

template <typename Scalar>
void ColorBar<Scalar>::setStartPoint(const Vector<Scalar, 3> & start_point)
{
    this->start_point_ = start_point;
}

template <typename Scalar>
void ColorBar<Scalar>::setXLength(Scalar x_len)
{
    this->x_len_ = x_len;
}

template <typename Scalar>
void ColorBar<Scalar>::setYLength(Scalar y_len)
{
    this->y_len_ = y_len;
}

template <typename Scalar>
void ColorBar<Scalar>::setZLength(Scalar z_len)
{
    this->z_len_ = z_len;
}

template <typename Scalar>
void ColorBar<Scalar>::setLength(Scalar x_len, Scalar y_len, Scalar z_len)
{
    this->x_len_ = x_len;
    this->y_len_ = y_len;
    this->z_len_ = z_len;
}

//explicit instantiations
template class ColorBar<float>;
template class ColorBar<double>;

}