#ifdef GL_ES
varying mediump vec2 TextureCoordOut;
#else
varying vec2 TextureCoordOut;
#endif

uniform sampler2D u_sampler0;

void main(void)
{
    gl_FragColor = texture2D(u_sampler0, TextureCoordOut);
}