// -*- glsl -*-
#if !defined(NATURAL_MYSTIC_AURORA_H_INCLUDED)
#define NATURAL_MYSTIC_AURORA_H_INCLUDED 1

/* Aurora borealis (northern lights), ported from NewB shader (devendrn/newb-x-mcbe).
 * Renders animated purple-teal curtains on the sky layer, visible only at night.
 *
 * p: sky position (use wPos from Sky vertex)
 * t: time in seconds (use ViewPositionAndTime.w)
 * nightFactor: 0.0 day .. 1.0 night (use isNight(FogColor))
 * clearWeather: 1.0 clear .. 0.0 rain (passed from vertex)
 */
vec4 renderAurora(vec3 p, float t, float nightFactor, float clearWeather) {
    t *= AURORA_VELOCITY;
    p.xz *= AURORA_SCALE;
    p.xz += 0.05 * sin(p.x * 4.0 + 20.0 * t);

    float d0 = sin(p.x * 0.1 + t + sin(p.z * 0.2));
    float d1 = sin(p.z * 0.1 - t + sin(p.x * 0.2));
    float d2 = sin(p.z * 0.1 + 1.0 * sin(d0 + d1 * 2.0) + d1 * 2.0 + d0 * 1.0);
    d0 *= d0;
    d1 *= d1;
    d2 *= d2;
    d2 = d0 / (1.0 + d2 / AURORA_WIDTH);

    float mask = nightFactor;
    mask *= mask * (1.0 - 0.8 * (1.0 - clearWeather));

    vec3 col = mix(AURORA_COL1, AURORA_COL2, d1);
    return vec4(AURORA_BRIGHTNESS * col, 1.0) * d2 * mask;
}

#endif /* !defined(NATURAL_MYSTIC_AURORA_H_INCLUDED) */
