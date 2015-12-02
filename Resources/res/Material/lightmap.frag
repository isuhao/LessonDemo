#ifdef GL_ES
varying mediump vec2 v_texture_coord;
varying mediump vec2 v_texture_coord1;
varying mediump float v_fogCoord;
#else
varying vec2 v_texture_coord;
varying vec2 v_texture_coord1;
varying float v_fogCoord;
#endif

uniform vec4 u_color;
uniform sampler2D u_lightMap;
uniform sampler2D u_texture0;

void main(void)
{
    vec4 mainColor = texture2D(u_texture0,v_texture_coord);
    vec4 lightColor = texture2D(u_lightMap,v_texture_coord1);
    vec4 resultColor = mainColor * lightColor;
    
    //blend two texture
    gl_FragColor = resultColor;
}