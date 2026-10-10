$input v_color0, wPos, cloudColor, camDist, clearWeather

#include "bgfx_shader.sh"

#if BGFX_SHADER_LANGUAGE_GLSL
	precision highp float;
	precision highp int;
#endif

#include "natural-mystic-config.h"
#include "natural-mystic-cloud.h"
#include "natural-mystic-hacks.h"
#include "natural-mystic-aurora.h"

uniform vec4 ViewPositionAndTime;
uniform vec4 FogColor;

void main() {
    vec4 skyCol;

#if defined(ENABLE_FBM_CLOUDS)
    vec4 shadedCloud = generateShadedClouds(6, ViewPositionAndTime.w, wPos, cloudColor, v_color0, clearWeather);

    /* Clouds near the horizon should be blended back to the sky
     * color, or otherwise the planar nature of the sky plane will be
     * even more apparent. */
    skyCol = mix(shadedCloud, v_color0, smoothstep(0.9, 1.0, camDist));

#else
    skyCol = v_color0;
#endif /* defined(ENABLE_FBM_CLOUDS) */

#if defined(ENABLE_AURORA)
    float nightFactor = isNight(FogColor);
    vec4 aurora = renderAurora(wPos, ViewPositionAndTime.w, nightFactor, clearWeather);
    /* Fade aurora near horizon to hide sky-plane edge, same as clouds. */
    aurora *= 1.0 - smoothstep(0.9, 1.0, camDist);
    skyCol.rgb += aurora.rgb;
#endif /* defined(ENABLE_AURORA) */

    gl_FragColor = skyCol;
}
