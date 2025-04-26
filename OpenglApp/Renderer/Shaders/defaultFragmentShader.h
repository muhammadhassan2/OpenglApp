//
//  defaultFragmentShader.h
//  OpenglApp
//
//  Created by Mohamed Hassan on 26/04/2025.
//

#pragma once

const static char *defaultFragmentShader = R"(

#version 330 core
out vec4 FragColor;
in vec2 tc;
uniform sampler2D texture0;
uniform sampler2D texture1;
void main(){
    vec4 ans = vec4(0.0);
    if(tc.x > .5) {
       ans = texture(texture0,tc);
     }
else{
  ans = texture(texture1,tc);
}
    FragColor = ans;
}
)";
