#if !defined(NATURAL_MYSTIC_CONFIG_H_INCLUDED)
#define NATURAL_MYSTIC_CONFIG_H_INCLUDED 1

#define FOG_TYPE_LINEAR 1
#define FOG_TYPE_EXP 2
#define FOG_TYPE_EXP2 3

/* Define to show the fog color. This is not compatible with other debug
   options. */
/* #undef DEBUG_SHOW_FOG_COLOR */

/* Define to show the fog control parameters. This is not compatible with
   other debug options. */
/* #undef DEBUG_SHOW_FOG_CONTROL */

/* Define to show the ambient occlusion factor. This is not compatible with
   other debug options. */
/* #undef DEBUG_SHOW_OCCLUSION_FACTOR */

/* Define to show the terrain-dependent sunlight level in grayscale. This is
   not compatible with other debug options. */
/* #undef DEBUG_SHOW_SUNLIGHT_LEVEL */

/* Define to show the color of vertices. This is not compatible with other
   debug options. */
/* #undef DEBUG_SHOW_VERTEX_COLOR */

/* Define to enable a thin fog that always affects the scene, not only when
   it's raining. */
#define ENABLE_BASE_FOG 1

/* Define to enable highlight and shade on shader-generated clouds. */
#define ENABLE_CLOUD_SHADE 1

/* Define to enable fancy water rendering. */
#define ENABLE_FANCY_WATER 1

/* Define to enable shader-generated clouds. */
#define ENABLE_FBM_CLOUDS 1

/* Define to enable cloud reflection on water. */
#define ENABLE_CLOUD_REFLECTION

/* Define to enable fake shadows generated from the ambient occlusion */
#define ENABLE_OCCLUSION_SHADOWS 1

/* Define to introduce randomness in the brighness of stars. */
#define ENABLE_RANDOM_STARS 1

/* Define to enable water ripple animation that appears on the ground when
   it's raining. */
#define ENABLE_RIPPLES 1

/* Define to enable the shader-generated sun and the moon. */
#define ENABLE_SHADER_SUN_MOON 1

/* Define to enable specular lighting. */
#define ENABLE_SPECULAR 1

/* Define to enable torch light flickering effect. */
#define ENABLE_TORCH_FLICKER 1

/* Define to enable aurora borealis (northern lights) at night, ported from NewB. */
#define ENABLE_AURORA 1

/* Aurora brightness. 0.4 dim ~ 4.0 very bright. */
#define AURORA_BRIGHTNESS 1.2

/* Aurora animation speed. 0.0 static ~ 0.3 very fast. */
#define AURORA_VELOCITY 0.03

/* Aurora pattern scale. 0.002 large ~ 0.4 tiny. */
#define AURORA_SCALE 0.04

/* Aurora curtain thickness. 0.04 thin ~ 0.4 thick. */
#define AURORA_WIDTH 0.18

/* Aurora colors: purple -> teal. */
#define AURORA_COL1 vec3(0.65, 0.2, 1.0)
#define AURORA_COL2 vec3(0.1, 1.0, 0.85)

/* Define to enable waves of water and leaves. */
#define ENABLE_WAVES 1

/* Define to one of FOG_TYPE_LINEAR and FOG_TYPE_EXP2 to choose a fog type to
   use. */
#define FOG_TYPE FOG_TYPE_EXP2

#endif /* NATURAL_MYSTIC_CONFIG_H_INCLUDED */
