attribute vec4 a_position;
attribute vec2 a_texCoord;
attribute vec2 a_texCoord1;

#ifdef GL_ES
varying mediump vec2 v_texture_coord;
varying mediump vec2 v_texture_coord1;
#else
varying vec2 v_texture_coord;
varying vec2 v_texture_coord1;
#endif


void main(void)
{
    gl_Position = CC_MVPMatrix * a_position;

    v_texture_coord = a_texCoord;
    v_texture_coord.y = (1.0 - v_texture_coord.y);

    v_texture_coord1 = a_texCoord1;
    v_texture_coord1.y = (1.0 - v_texture_coord1.y);
}
