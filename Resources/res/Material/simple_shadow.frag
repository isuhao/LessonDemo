#ifdef GL_ES
varying mediump vec2 v_texture_coord;
varying mediump vec4 v_position;
#else
varying vec2 v_texture_coord;
varying vec4 v_position;
#endif
uniform sampler2D u_sampler0;
uniform sampler2D u_sampler1;
uniform vec3 u_target_pos;
uniform vec4 u_color;
uniform float u_radius;
void main(void)
{

	vec3 UVector = vec3(1.0, 0.0, 0.0)/(2.0 * u_radius);
	vec3 VVector = vec3(0.0, 0.0, 1.0)/(2.0 * u_radius);
	vec2 coord;  
    coord.x = dot(v_position.xyz - u_target_pos, UVector) + 0.5;
    coord.y = dot(v_position.xyz - u_target_pos, VVector) + 0.5;

    gl_FragColor = u_color*texture2D(u_sampler0,v_texture_coord)*texture2D(u_sampler1,coord);
}