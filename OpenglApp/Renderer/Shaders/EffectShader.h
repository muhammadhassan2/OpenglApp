//
//  EffectShader.h
//  OpenglApp
//
//  Created by Mohamed Hassan on 27/04/2025.
//

#pragma once

const static char *EffectShader = R"(

#version 330 core
out vec4 FragColor;
in vec2 tc;
uniform sampler2D texture0;
void main(){

               vec2 TexCoord = tc; 
               TexCoord.y = 1.0 - TexCoord.y; 
               vec2 uv = TexCoord - vec2(0.5, 0.5);
               float zoom = 1.0 + 1.0 * sin(1.3 * 3.14159 * 3.0);
               float angle = 1.5 * 2.0 * 3.14159 * 3.0;
               mat2 rotation = mat2(
                   cos(angle*3.0), -sin(angle),
                   sin(angle), cos(angle)
               );
               uv = rotation * uv / zoom;
               uv += vec2(0.5, 0.5);
               vec4 color = texture(texture0, vec2(uv.x, 1.0 - uv.y));
               if (uv.x < 0.0 || uv.x > 1.0 || uv.y < 0.0 || uv.y > 1.0) {
                   color = vec4(0.0, 0.0, 0.0, 1.0);
               }
                   FragColor = vec4(1.0);
}
)";
