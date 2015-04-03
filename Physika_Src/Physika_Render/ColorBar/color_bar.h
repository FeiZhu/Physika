/*
 * @file color_bar.h 
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

#ifndef PHYSIKA_RENDER_COLORBAR_COLOR_BAR_H_
#define PHYSIKA_RENDER_COLORBAR_COLOR_BAR_H_

#include "Physika_Render/ColorBar/ColorMap/color_map.h"
#include "Physika_Core/Vectors/vector_3d.h"

namespace Physika{

template <typename Scalar>
class ColorBar
{
public:
    ColorBar();
    ~ColorBar();

    //getter
    const Vector<Scalar, 3> & startPoint() const;
    Scalar xLength() const;
    Scalar yLength() const;
    Scalar zLength() const;
    const ColorMap<Scalar> & colorMap() const;

    //setter
    void setColorMap(const ColorMap<Scalar> & color_map);
    void setColorMapSize(unsigned int color_size);
    void setColorMapType(ColorMapType color_map_type);
    void setColorMapTypeAndSize(ColorMapType color_map_type, unsigned int color_size);
    void setStartPoint(const Vector<Scalar, 3> & start_point);
    void setXLength(Scalar x_len);
    void setYLength(Scalar y_len);
    void setZLength(Scalar z_len);
    void setLength(Scalar x_len, Scalar y_len, Scalar z_len);

protected:
    ColorMap<Scalar> color_map_;
    Vector<Scalar,3> start_point_; // left bottom corner
    Scalar x_len_;
    Scalar y_len_;
    Scalar z_len_;
};


} // end of namespace Physika

#endif //PHYSIKA_RENDER_COLORBAR_COLOR_BAR_H