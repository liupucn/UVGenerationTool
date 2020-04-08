static const uint8_t fs_material_gl[1331] =
{
	0x46, 0x53, 0x48, 0x06, 0x91, 0xb0, 0x36, 0xc4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x05, // FSH...6....... .
	0x00, 0x00, 0x69, 0x6e, 0x20, 0x76, 0x65, 0x63, 0x33, 0x20, 0x76, 0x5f, 0x6e, 0x6f, 0x72, 0x6d, // ..in vec3 v_norm
	0x61, 0x6c, 0x3b, 0x0a, 0x63, 0x65, 0x6e, 0x74, 0x72, 0x6f, 0x69, 0x64, 0x20, 0x69, 0x6e, 0x20, // al;.centroid in 
	0x76, 0x65, 0x63, 0x34, 0x20, 0x76, 0x5f, 0x74, 0x65, 0x78, 0x63, 0x6f, 0x6f, 0x72, 0x64, 0x30, // vec4 v_texcoord0
	0x3b, 0x0a, 0x75, 0x6e, 0x69, 0x66, 0x6f, 0x72, 0x6d, 0x20, 0x73, 0x61, 0x6d, 0x70, 0x6c, 0x65, // ;.uniform sample
	0x72, 0x32, 0x44, 0x20, 0x73, 0x5f, 0x64, 0x69, 0x66, 0x66, 0x75, 0x73, 0x65, 0x3b, 0x0a, 0x75, // r2D s_diffuse;.u
	0x6e, 0x69, 0x66, 0x6f, 0x72, 0x6d, 0x20, 0x73, 0x61, 0x6d, 0x70, 0x6c, 0x65, 0x72, 0x32, 0x44, // niform sampler2D
	0x20, 0x73, 0x5f, 0x65, 0x6d, 0x69, 0x73, 0x73, 0x69, 0x6f, 0x6e, 0x3b, 0x0a, 0x75, 0x6e, 0x69, //  s_emission;.uni
	0x66, 0x6f, 0x72, 0x6d, 0x20, 0x73, 0x61, 0x6d, 0x70, 0x6c, 0x65, 0x72, 0x32, 0x44, 0x20, 0x73, // form sampler2D s
	0x5f, 0x6c, 0x69, 0x67, 0x68, 0x74, 0x6d, 0x61, 0x70, 0x3b, 0x0a, 0x75, 0x6e, 0x69, 0x66, 0x6f, // _lightmap;.unifo
	0x72, 0x6d, 0x20, 0x76, 0x65, 0x63, 0x34, 0x20, 0x75, 0x5f, 0x64, 0x69, 0x66, 0x66, 0x75, 0x73, // rm vec4 u_diffus
	0x65, 0x3b, 0x0a, 0x75, 0x6e, 0x69, 0x66, 0x6f, 0x72, 0x6d, 0x20, 0x76, 0x65, 0x63, 0x34, 0x20, // e;.uniform vec4 
	0x75, 0x5f, 0x65, 0x6d, 0x69, 0x73, 0x73, 0x69, 0x6f, 0x6e, 0x3b, 0x0a, 0x75, 0x6e, 0x69, 0x66, // u_emission;.unif
	0x6f, 0x72, 0x6d, 0x20, 0x76, 0x65, 0x63, 0x34, 0x20, 0x75, 0x5f, 0x6c, 0x69, 0x67, 0x68, 0x74, // orm vec4 u_light
	0x44, 0x69, 0x72, 0x3b, 0x0a, 0x75, 0x6e, 0x69, 0x66, 0x6f, 0x72, 0x6d, 0x20, 0x76, 0x65, 0x63, // Dir;.uniform vec
	0x34, 0x20, 0x75, 0x5f, 0x73, 0x68, 0x61, 0x64, 0x65, 0x5f, 0x64, 0x69, 0x66, 0x66, 0x75, 0x73, // 4 u_shade_diffus
	0x65, 0x5f, 0x65, 0x6d, 0x69, 0x73, 0x73, 0x69, 0x6f, 0x6e, 0x3b, 0x0a, 0x76, 0x6f, 0x69, 0x64, // e_emission;.void
	0x20, 0x6d, 0x61, 0x69, 0x6e, 0x20, 0x28, 0x29, 0x0a, 0x7b, 0x0a, 0x20, 0x20, 0x76, 0x65, 0x63, //  main ().{.  vec
	0x34, 0x20, 0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x5f, 0x31, 0x3b, 0x0a, 0x20, 0x20, 0x76, 0x65, 0x63, // 4 color_1;.  vec
	0x34, 0x20, 0x65, 0x6d, 0x69, 0x73, 0x73, 0x69, 0x6f, 0x6e, 0x5f, 0x32, 0x3b, 0x0a, 0x20, 0x20, // 4 emission_2;.  
	0x65, 0x6d, 0x69, 0x73, 0x73, 0x69, 0x6f, 0x6e, 0x5f, 0x32, 0x20, 0x3d, 0x20, 0x75, 0x5f, 0x65, // emission_2 = u_e
	0x6d, 0x69, 0x73, 0x73, 0x69, 0x6f, 0x6e, 0x3b, 0x0a, 0x20, 0x20, 0x69, 0x66, 0x20, 0x28, 0x28, // mission;.  if ((
	0x75, 0x69, 0x6e, 0x74, 0x28, 0x75, 0x5f, 0x73, 0x68, 0x61, 0x64, 0x65, 0x5f, 0x64, 0x69, 0x66, // uint(u_shade_dif
	0x66, 0x75, 0x73, 0x65, 0x5f, 0x65, 0x6d, 0x69, 0x73, 0x73, 0x69, 0x6f, 0x6e, 0x2e, 0x7a, 0x29, // fuse_emission.z)
	0x20, 0x3d, 0x3d, 0x20, 0x31, 0x75, 0x29, 0x29, 0x20, 0x7b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x65, //  == 1u)) {.    e
	0x6d, 0x69, 0x73, 0x73, 0x69, 0x6f, 0x6e, 0x5f, 0x32, 0x2e, 0x78, 0x79, 0x7a, 0x20, 0x3d, 0x20, // mission_2.xyz = 
	0x74, 0x65, 0x78, 0x74, 0x75, 0x72, 0x65, 0x20, 0x28, 0x73, 0x5f, 0x65, 0x6d, 0x69, 0x73, 0x73, // texture (s_emiss
	0x69, 0x6f, 0x6e, 0x2c, 0x20, 0x76, 0x5f, 0x74, 0x65, 0x78, 0x63, 0x6f, 0x6f, 0x72, 0x64, 0x30, // ion, v_texcoord0
	0x2e, 0x78, 0x79, 0x29, 0x2e, 0x78, 0x79, 0x7a, 0x3b, 0x0a, 0x20, 0x20, 0x7d, 0x3b, 0x0a, 0x20, // .xy).xyz;.  };. 
	0x20, 0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x5f, 0x31, 0x20, 0x3d, 0x20, 0x76, 0x65, 0x63, 0x34, 0x28, //  color_1 = vec4(
	0x30, 0x2e, 0x30, 0x2c, 0x20, 0x30, 0x2e, 0x30, 0x2c, 0x20, 0x30, 0x2e, 0x30, 0x2c, 0x20, 0x31, // 0.0, 0.0, 0.0, 1
	0x2e, 0x30, 0x29, 0x3b, 0x0a, 0x20, 0x20, 0x69, 0x66, 0x20, 0x28, 0x28, 0x28, 0x28, 0x65, 0x6d, // .0);.  if ((((em
	0x69, 0x73, 0x73, 0x69, 0x6f, 0x6e, 0x5f, 0x32, 0x2e, 0x78, 0x20, 0x3e, 0x20, 0x30, 0x2e, 0x30, // ission_2.x > 0.0
	0x29, 0x20, 0x7c, 0x7c, 0x20, 0x28, 0x65, 0x6d, 0x69, 0x73, 0x73, 0x69, 0x6f, 0x6e, 0x5f, 0x32, // ) || (emission_2
	0x2e, 0x79, 0x20, 0x3e, 0x20, 0x30, 0x2e, 0x30, 0x29, 0x29, 0x20, 0x7c, 0x7c, 0x20, 0x28, 0x65, // .y > 0.0)) || (e
	0x6d, 0x69, 0x73, 0x73, 0x69, 0x6f, 0x6e, 0x5f, 0x32, 0x2e, 0x7a, 0x20, 0x3e, 0x20, 0x30, 0x2e, // mission_2.z > 0.
	0x30, 0x29, 0x29, 0x29, 0x20, 0x7b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x63, 0x6f, 0x6c, 0x6f, 0x72, // 0))) {.    color
	0x5f, 0x31, 0x20, 0x3d, 0x20, 0x65, 0x6d, 0x69, 0x73, 0x73, 0x69, 0x6f, 0x6e, 0x5f, 0x32, 0x3b, // _1 = emission_2;
	0x0a, 0x20, 0x20, 0x7d, 0x20, 0x65, 0x6c, 0x73, 0x65, 0x20, 0x7b, 0x0a, 0x20, 0x20, 0x20, 0x20, // .  } else {.    
	0x76, 0x65, 0x63, 0x34, 0x20, 0x64, 0x69, 0x66, 0x66, 0x75, 0x73, 0x65, 0x5f, 0x33, 0x3b, 0x0a, // vec4 diffuse_3;.
	0x20, 0x20, 0x20, 0x20, 0x64, 0x69, 0x66, 0x66, 0x75, 0x73, 0x65, 0x5f, 0x33, 0x20, 0x3d, 0x20, //     diffuse_3 = 
	0x75, 0x5f, 0x64, 0x69, 0x66, 0x66, 0x75, 0x73, 0x65, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x69, // u_diffuse;.    i
	0x66, 0x20, 0x28, 0x28, 0x75, 0x69, 0x6e, 0x74, 0x28, 0x75, 0x5f, 0x73, 0x68, 0x61, 0x64, 0x65, // f ((uint(u_shade
	0x5f, 0x64, 0x69, 0x66, 0x66, 0x75, 0x73, 0x65, 0x5f, 0x65, 0x6d, 0x69, 0x73, 0x73, 0x69, 0x6f, // _diffuse_emissio
	0x6e, 0x2e, 0x79, 0x29, 0x20, 0x3d, 0x3d, 0x20, 0x31, 0x75, 0x29, 0x29, 0x20, 0x7b, 0x0a, 0x20, // n.y) == 1u)) {. 
	0x20, 0x20, 0x20, 0x20, 0x20, 0x64, 0x69, 0x66, 0x66, 0x75, 0x73, 0x65, 0x5f, 0x33, 0x20, 0x3d, //      diffuse_3 =
	0x20, 0x28, 0x75, 0x5f, 0x64, 0x69, 0x66, 0x66, 0x75, 0x73, 0x65, 0x20, 0x2a, 0x20, 0x74, 0x65, //  (u_diffuse * te
	0x78, 0x74, 0x75, 0x72, 0x65, 0x20, 0x28, 0x73, 0x5f, 0x64, 0x69, 0x66, 0x66, 0x75, 0x73, 0x65, // xture (s_diffuse
	0x2c, 0x20, 0x76, 0x5f, 0x74, 0x65, 0x78, 0x63, 0x6f, 0x6f, 0x72, 0x64, 0x30, 0x2e, 0x78, 0x79, // , v_texcoord0.xy
	0x29, 0x29, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x7d, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x69, // ));.    };.    i
	0x66, 0x20, 0x28, 0x28, 0x75, 0x69, 0x6e, 0x74, 0x28, 0x75, 0x5f, 0x73, 0x68, 0x61, 0x64, 0x65, // f ((uint(u_shade
	0x5f, 0x64, 0x69, 0x66, 0x66, 0x75, 0x73, 0x65, 0x5f, 0x65, 0x6d, 0x69, 0x73, 0x73, 0x69, 0x6f, // _diffuse_emissio
	0x6e, 0x2e, 0x78, 0x29, 0x20, 0x3d, 0x3d, 0x20, 0x75, 0x69, 0x6e, 0x74, 0x28, 0x30, 0x29, 0x29, // n.x) == uint(0))
	0x29, 0x20, 0x7b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x5f, // ) {.      color_
	0x31, 0x2e, 0x78, 0x79, 0x7a, 0x20, 0x3d, 0x20, 0x28, 0x64, 0x69, 0x66, 0x66, 0x75, 0x73, 0x65, // 1.xyz = (diffuse
	0x5f, 0x33, 0x2e, 0x78, 0x79, 0x7a, 0x20, 0x2a, 0x20, 0x28, 0x28, 0x0a, 0x20, 0x20, 0x20, 0x20, // _3.xyz * ((.    
	0x20, 0x20, 0x20, 0x20, 0x64, 0x6f, 0x74, 0x20, 0x28, 0x76, 0x5f, 0x6e, 0x6f, 0x72, 0x6d, 0x61, //     dot (v_norma
	0x6c, 0x2c, 0x20, 0x75, 0x5f, 0x6c, 0x69, 0x67, 0x68, 0x74, 0x44, 0x69, 0x72, 0x2e, 0x78, 0x79, // l, u_lightDir.xy
	0x7a, 0x29, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x2a, 0x20, 0x30, 0x2e, 0x35, 0x29, // z).       * 0.5)
	0x20, 0x2b, 0x20, 0x30, 0x2e, 0x35, 0x29, 0x29, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x7d, 0x20, //  + 0.5));.    } 
	0x65, 0x6c, 0x73, 0x65, 0x20, 0x7b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x69, 0x66, 0x20, // else {.      if 
	0x28, 0x28, 0x75, 0x69, 0x6e, 0x74, 0x28, 0x75, 0x5f, 0x73, 0x68, 0x61, 0x64, 0x65, 0x5f, 0x64, // ((uint(u_shade_d
	0x69, 0x66, 0x66, 0x75, 0x73, 0x65, 0x5f, 0x65, 0x6d, 0x69, 0x73, 0x73, 0x69, 0x6f, 0x6e, 0x2e, // iffuse_emission.
	0x78, 0x29, 0x20, 0x3d, 0x3d, 0x20, 0x31, 0x75, 0x29, 0x29, 0x20, 0x7b, 0x0a, 0x20, 0x20, 0x20, // x) == 1u)) {.   
	0x20, 0x20, 0x20, 0x20, 0x20, 0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x5f, 0x31, 0x2e, 0x78, 0x79, 0x7a, //      color_1.xyz
	0x20, 0x3d, 0x20, 0x28, 0x64, 0x69, 0x66, 0x66, 0x75, 0x73, 0x65, 0x5f, 0x33, 0x2e, 0x78, 0x79, //  = (diffuse_3.xy
	0x7a, 0x20, 0x2a, 0x20, 0x74, 0x65, 0x78, 0x74, 0x75, 0x72, 0x65, 0x20, 0x28, 0x73, 0x5f, 0x6c, // z * texture (s_l
	0x69, 0x67, 0x68, 0x74, 0x6d, 0x61, 0x70, 0x2c, 0x20, 0x76, 0x5f, 0x74, 0x65, 0x78, 0x63, 0x6f, // ightmap, v_texco
	0x6f, 0x72, 0x64, 0x30, 0x2e, 0x7a, 0x77, 0x29, 0x2e, 0x78, 0x79, 0x7a, 0x29, 0x3b, 0x0a, 0x20, // ord0.zw).xyz);. 
	0x20, 0x20, 0x20, 0x20, 0x20, 0x7d, 0x20, 0x65, 0x6c, 0x73, 0x65, 0x20, 0x7b, 0x0a, 0x20, 0x20, //      } else {.  
	0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x69, 0x66, 0x20, 0x28, 0x28, 0x75, 0x69, 0x6e, 0x74, 0x28, //       if ((uint(
	0x75, 0x5f, 0x73, 0x68, 0x61, 0x64, 0x65, 0x5f, 0x64, 0x69, 0x66, 0x66, 0x75, 0x73, 0x65, 0x5f, // u_shade_diffuse_
	0x65, 0x6d, 0x69, 0x73, 0x73, 0x69, 0x6f, 0x6e, 0x2e, 0x78, 0x29, 0x20, 0x3d, 0x3d, 0x20, 0x32, // emission.x) == 2
	0x75, 0x29, 0x29, 0x20, 0x7b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, // u)) {.          
	0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x5f, 0x31, 0x2e, 0x78, 0x79, 0x7a, 0x20, 0x3d, 0x20, 0x74, 0x65, // color_1.xyz = te
	0x78, 0x74, 0x75, 0x72, 0x65, 0x20, 0x28, 0x73, 0x5f, 0x6c, 0x69, 0x67, 0x68, 0x74, 0x6d, 0x61, // xture (s_lightma
	0x70, 0x2c, 0x20, 0x76, 0x5f, 0x74, 0x65, 0x78, 0x63, 0x6f, 0x6f, 0x72, 0x64, 0x30, 0x2e, 0x7a, // p, v_texcoord0.z
	0x77, 0x29, 0x2e, 0x78, 0x79, 0x7a, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, // w).xyz;.        
	0x7d, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x7d, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, // };.      };.    
	0x7d, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x5f, 0x31, 0x2e, 0x77, // };.    color_1.w
	0x20, 0x3d, 0x20, 0x64, 0x69, 0x66, 0x66, 0x75, 0x73, 0x65, 0x5f, 0x33, 0x2e, 0x77, 0x3b, 0x0a, //  = diffuse_3.w;.
	0x20, 0x20, 0x7d, 0x3b, 0x0a, 0x20, 0x20, 0x67, 0x6c, 0x5f, 0x46, 0x72, 0x61, 0x67, 0x43, 0x6f, //   };.  gl_FragCo
	0x6c, 0x6f, 0x72, 0x20, 0x3d, 0x20, 0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x5f, 0x31, 0x3b, 0x0a, 0x7d, // lor = color_1;.}
	0x0a, 0x0a, 0x00,                                                                               // ...
};