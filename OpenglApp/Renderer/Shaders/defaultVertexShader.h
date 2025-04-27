//
//  defaultVertexShader.h
//  OpenglApp
//
//  Created by Mohamed Hassan on 26/04/2025.
//

#pragma once

const static char *defaultVertexShader = R"(

#version 330 core
layout (location = 0) in vec3 apos;
layout (location = 1) in vec2 aTex;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;
uniform mat4 camera;
out vec2 tc;

void main(){
       // gl_Position = model * view * proj  *  vec4(apos.x, apos.y , apos.z,1.0);
       // gl_Position = proj * view * model  *  vec4(apos.x, apos.y , apos.z,1.0);
       gl_Position = camera * vec4(apos.x, apos.y , apos.z,1.0);
        tc = aTex; 
}
)";
