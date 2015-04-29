/*
 * @file colorbar_module_test.cpp 
 * @brief Test color bar of Physika.
 * @author WeiChen
 * 
 * This file is part of Physika, a versatile physics simulation library.
 * Copyright (C) 2013 Physika Group.
 *
 * This Source Code Form is subject to the terms of the GNU General Public License v2.0. 
 * If a copy of the GPL was not distributed with this file, you can obtain one at:
 * http://www.gnu.org/licenses/gpl-2.0.html
 *
 */

#include <iostream>
#include <GL/freeglut.h>
#include <GL/glui.h>
#include "Physika_Core/Vectors/vector_3d.h"
#include "Physika_Core/Utilities/physika_assert.h"
#include "Physika_Render/OpenGL_Primitives/opengl_primitives.h"
#include "Physika_GUI/Glut_Window/glut_window.h"
#include "Physika_Render/ColorBar_Render/color_bar_render.h"

using namespace std;
using namespace Physika;

ColorMap<double> gray_colormap;
ColorMap<double> red_colormap;
ColorMap<double> green_colormap;
ColorMap<double> blue_colormap;
ColorMap<double> jet_colormap;
ColorMap<double> spring_colormap;
ColorMap<double> summer_colormap;
ColorMap<double> autumn_colormap;
ColorMap<double> winter_colormap;
ColorMap<double> hot_colormap;
ColorMap<double> cool_colormap;

ColorBar<double> gray_color_bar;
ColorBar<double> red_color_bar;
ColorBar<double> green_color_bar;
ColorBar<double> blue_color_bar;
ColorBar<double> jet_color_bar;
ColorBar<double> spring_color_bar;
ColorBar<double> summer_color_bar;
ColorBar<double> autumn_color_bar;
ColorBar<double> winter_color_bar;
ColorBar<double> hot_color_bar;
ColorBar<double> cool_color_bar;

ColorBarRender<double> gray_colorbar_render;
ColorBarRender<double> red_colorbar_render;
ColorBarRender<double> blue_colorbar_render;
ColorBarRender<double> green_colorbar_render;
ColorBarRender<double> jet_colorbar_render;
ColorBarRender<double> spring_colorbar_render;
ColorBarRender<double> summer_colorbar_render;
ColorBarRender<double> autumn_colorbar_render;
ColorBarRender<double> winter_colorbar_render;
ColorBarRender<double> hot_colorbar_render;
ColorBarRender<double> cool_colorbar_render;


void displayFunction()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		     // Clear Screen and Depth Buffer
    GlutWindow *cur_window = (GlutWindow*)glutGetWindowData();
    //cur_window->orbitCameraRight(0.1);
	
    //(cur_window->camera()).look();
	//cur_window->lightAtIndex(0)->setPosition(Vector<float,3>(0,50,0));
	cur_window->applyCameraAndLights();

    gray_colorbar_render.render();
    red_colorbar_render.render();
    green_colorbar_render.render();
    blue_colorbar_render.render();
    jet_colorbar_render.render();
    spring_colorbar_render.render();
    summer_colorbar_render.render();
    autumn_colorbar_render.render();
    winter_colorbar_render.render();
    hot_colorbar_render.render();
    cool_colorbar_render.render();

    cur_window->displayFrameRate();
    glutSwapBuffers();
}

void idleFunction()
{
    cout<<"Custom idle function\n";
}

void initFunction()
{
    gray_colormap.setColorMapTypeAndSize(ColorMapType::Gray, 16);
    red_colormap.setColorMapTypeAndSize(ColorMapType::Red, 16);
    green_colormap.setColorMapTypeAndSize(ColorMapType::Green, 16);
    blue_colormap.setColorMapTypeAndSize(ColorMapType::Blue, 16);
    jet_colormap.setColorMapTypeAndSize(ColorMapType::Jet, 16);
    spring_colormap.setColorMapTypeAndSize(ColorMapType::Spring, 16);
    summer_colormap.setColorMapTypeAndSize(ColorMapType::Summer, 16);
    autumn_colormap.setColorMapTypeAndSize(ColorMapType::Autumn, 16);
    winter_colormap.setColorMapTypeAndSize(ColorMapType::Winter, 16);
    hot_colormap.setColorMapTypeAndSize(ColorMapType::Hot, 16);
    cool_colormap.setColorMapTypeAndSize(ColorMapType::Cool, 16);

    cout<<jet_colormap<<endl;

    gray_color_bar.setColorMapTypeAndSize(ColorMapType::Gray, 256);
    gray_color_bar.setStartPoint(Vector<double,2>(10,70));
    gray_colorbar_render.setColorBar(&gray_color_bar);

    red_color_bar.setColorMapTypeAndSize(ColorMapType::Red, 256);
    red_color_bar.setStartPoint(Vector<double,2>(40,70));
    red_colorbar_render.setColorBar(&red_color_bar);

    green_color_bar.setColorMapTypeAndSize(ColorMapType::Green, 256);
    green_color_bar.setStartPoint(Vector<double,2>(70,70));
    green_colorbar_render.setColorBar(&green_color_bar);

    blue_color_bar.setColorMapTypeAndSize(ColorMapType::Blue, 256);
    blue_color_bar.setStartPoint(Vector<double,2>(100,70));
    blue_colorbar_render.setColorBar(&blue_color_bar);

    jet_color_bar.setColorMapTypeAndSize(ColorMapType::Jet, 256);
    jet_color_bar.setStartPoint(Vector<double,2>(130,70));
    jet_colorbar_render.setColorBar(&jet_color_bar);

    spring_color_bar.setColorMapTypeAndSize(ColorMapType::Spring, 256);
    spring_color_bar.setStartPoint(Vector<double,2>(160,70));
    spring_colorbar_render.setColorBar(&spring_color_bar);

    summer_color_bar.setColorMapTypeAndSize(ColorMapType::Summer, 256);
    summer_color_bar.setStartPoint(Vector<double,2>(190,70));
    summer_colorbar_render.setColorBar(&summer_color_bar);

    autumn_color_bar.setColorMapTypeAndSize(ColorMapType::Autumn, 256);
    autumn_color_bar.setStartPoint(Vector<double,2>(220,70));
    autumn_colorbar_render.setColorBar(&autumn_color_bar);

    winter_color_bar.setColorMapTypeAndSize(ColorMapType::Winter, 256);
    winter_color_bar.setStartPoint(Vector<double,2>(250,70));
    winter_colorbar_render.setColorBar(&winter_color_bar);

    hot_color_bar.setColorMapTypeAndSize(ColorMapType::Hot, 256);
    hot_color_bar.setStartPoint(Vector<double,2>(280,70));
    hot_colorbar_render.setColorBar(&hot_color_bar);

    cool_color_bar.setColorMapTypeAndSize(ColorMapType::Cool, 256);
    cool_color_bar.setStartPoint(Vector<double,2>(310,70));
    cool_color_bar.enableHorizon();
    cool_colorbar_render.setColorBar(&cool_color_bar);

	/***********************************************************************/
	// note: we have to set our light in initFunction, otherwise the setting will not be vaild.

	GlutWindow *cur_window = (GlutWindow*)glutGetWindowData();
	cur_window->lightAtIndex(0)->setPosition(Vector<float,3>(0,50,0));
	cur_window->lightAtIndex(0)->turnOn();

    glClearDepth(1.0);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);	
	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);	
	glClearColor( 0.0, 0.0, 0.0, 1.0 );

	glShadeModel( GL_SMOOTH );
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
}

void keyboardFunction(unsigned char key, int x, int y )
{
    GlutWindow::bindDefaultKeys(key,x,y);
    switch(key)
    {
    case 't':
        cout<<"test\n";
        break;
    default:
        break;
    }
}

int main()
{
    GlutWindow glut_window;
    cout<<"Window name: "<<glut_window.name()<<"\n";
    cout<<"Window size: "<<glut_window.width()<<"x"<<glut_window.height()<<"\n";
    glut_window.setCameraPosition(Vector<double,3>(0,0,200));
    glut_window.setCameraFocusPosition(Vector<double,3>(0,0,0));
    glut_window.setCameraNearClip(0.1);
    glut_window.setCameraFarClip(1.0e4);
    glut_window.setDisplayFunction(displayFunction);
    //glut_window.setIdleFunction(idleFunction);
    glut_window.setInitFunction(initFunction);
    cout<<"Test GlutWindow with custom display function:\n";
    glut_window.createWindow();
    cout<<"Window size: "<<glut_window.width()<<"x"<<glut_window.height()<<"\n";
    cout<<"Test window with GLUI controls:\n";
    return 0;
}