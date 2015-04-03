/*
 * @file color_bar_render.cpp 
 * @Brief render of color bar.
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

#include "Physika_Render/OpenGL_Primitives/opengl_primitives.h"
# include "Physika_Render/ColorBar_Render/color_bar_render.h"

namespace Physika{

template <typename Scalar>
ColorBarRender<Scalar>::ColorBarRender()
    :color_bar_(NULL)
{

}

template <typename Scalar>
ColorBarRender<Scalar>::ColorBarRender(ColorBar<Scalar> * color_bar)
    :color_bar_(color_bar)
{

}

template <typename Scalar>
ColorBarRender<Scalar>::~ColorBarRender()
{

}

template <typename Scalar>
const ColorBar<Scalar> * ColorBarRender<Scalar>::colorBar() const
{
    return this->color_bar_;
}

template <typename Scalar>
void ColorBarRender<Scalar>::setColorBar(ColorBar<Scalar> * color_bar)
{
    if (color_bar == NULL)
    {
        std::cerr<<"can't set NULL color bar!\n";
        std::exit(EXIT_FAILURE);
    }
    this->color_bar_ = color_bar;
}

template <typename Scalar>
void ColorBarRender<Scalar>::render()
{
    glPushAttrib(GL_LIGHTING_BIT|GL_POLYGON_BIT|GL_ENABLE_BIT|GL_TEXTURE_BIT);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // set polygon mode FILL for SOLID MODE
    glDisable(GL_LIGHTING);                    // disable lighting to display the color

    glPushMatrix();
    const ColorMap<Scalar> & color_map = this->color_bar_->colorMap();
    unsigned int color_map_size = color_map.colorMapSize();

    Scalar dx = this->color_bar_->xLength();
    Scalar dy = this->color_bar_->yLength()/color_map_size;
    Scalar dz = -this->color_bar_->zLength();

    for (unsigned int i=0 ; i<color_map_size; i++)
    {
        Vector<Scalar, 3> start_pos = this->color_bar_->startPoint();
        start_pos[1] += i*dy;
        Color<Scalar> color = color_map.colorViaIndex(i);
        this->drawBox(start_pos, dx, dy, dz, color);
    }

    glPopMatrix();
    glPopAttrib();
}

template <typename Scalar>
void ColorBarRender<Scalar>::drawBox(const Vector<Scalar, 3> & start_pos, Scalar dx, Scalar dy, Scalar dz, const Color<Scalar> & color)
{
    Vector<Scalar,3> position_0 = start_pos;
    Vector<Scalar,3> position_1 = start_pos+Vector<Scalar,3>(dx,0, 0);
    Vector<Scalar,3> position_2 = start_pos+Vector<Scalar,3>(dx,0, dz);
    Vector<Scalar,3> position_3 = start_pos+Vector<Scalar,3>(0, 0, dz);
    Vector<Scalar,3> position_4 = start_pos+Vector<Scalar,3>(0, dy, 0);
    Vector<Scalar,3> position_5 = start_pos+Vector<Scalar,3>(dx,dy,0);
    Vector<Scalar,3> position_6 = start_pos+Vector<Scalar,3>(dx,dy,dz);
    Vector<Scalar,3> position_7 = start_pos+Vector<Scalar,3>(0 ,dy,dz);

    openGLColor3(color);

    glBegin(GL_POLYGON);
    openGLVertex(position_0);
    openGLVertex(position_3);
    openGLVertex(position_2);
    openGLVertex(position_1);
    glEnd();

    glBegin(GL_POLYGON);
    openGLVertex(position_4);
    openGLVertex(position_5);
    openGLVertex(position_6);
    openGLVertex(position_7);
    glEnd();

    glBegin(GL_POLYGON);
    openGLVertex(position_0);
    openGLVertex(position_1);
    openGLVertex(position_5);
    openGLVertex(position_4);
    glEnd();

    glBegin(GL_POLYGON);
    openGLVertex(position_3);
    openGLVertex(position_7);
    openGLVertex(position_6);
    openGLVertex(position_2);
    glEnd();

    glBegin(GL_POLYGON);
    openGLVertex(position_4);
    openGLVertex(position_7);
    openGLVertex(position_3);
    openGLVertex(position_0);
    glEnd();

    glBegin(GL_POLYGON);
    openGLVertex(position_1);
    openGLVertex(position_2);
    openGLVertex(position_6);
    openGLVertex(position_5);
    glEnd();
}

//explicit instantiation
template class ColorBarRender<float>;
template class ColorBarRender<double>;

}// end of namespace Physika