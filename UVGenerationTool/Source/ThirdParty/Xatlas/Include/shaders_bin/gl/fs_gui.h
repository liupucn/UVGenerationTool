static const uint8_t fs_gui_gl[181] =
{
	0x46, 0x53, 0x48, 0x06, 0x01, 0x83, 0xf2, 0xe1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa2, 0x00, // FSH.............
	0x00, 0x00, 0x69, 0x6e, 0x20, 0x76, 0x65, 0x63, 0x34, 0x20, 0x76, 0x5f, 0x63, 0x6f, 0x6c, 0x6f, // ..in vec4 v_colo
	0x72, 0x30, 0x3b, 0x0a, 0x63, 0x65, 0x6e, 0x74, 0x72, 0x6f, 0x69, 0x64, 0x20, 0x69, 0x6e, 0x20, // r0;.centroid in 
	0x76, 0x65, 0x63, 0x34, 0x20, 0x76, 0x5f, 0x74, 0x65, 0x78, 0x63, 0x6f, 0x6f, 0x72, 0x64, 0x30, // vec4 v_texcoord0
	0x3b, 0x0a, 0x75, 0x6e, 0x69, 0x66, 0x6f, 0x72, 0x6d, 0x20, 0x73, 0x61, 0x6d, 0x70, 0x6c, 0x65, // ;.uniform sample
	0x72, 0x32, 0x44, 0x20, 0x73, 0x5f, 0x74, 0x65, 0x78, 0x74, 0x75, 0x72, 0x65, 0x3b, 0x0a, 0x76, // r2D s_texture;.v
	0x6f, 0x69, 0x64, 0x20, 0x6d, 0x61, 0x69, 0x6e, 0x20, 0x28, 0x29, 0x0a, 0x7b, 0x0a, 0x20, 0x20, // oid main ().{.  
	0x67, 0x6c, 0x5f, 0x46, 0x72, 0x61, 0x67, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x20, 0x3d, 0x20, 0x28, // gl_FragColor = (
	0x76, 0x5f, 0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x30, 0x20, 0x2a, 0x20, 0x74, 0x65, 0x78, 0x74, 0x75, // v_color0 * textu
	0x72, 0x65, 0x20, 0x28, 0x73, 0x5f, 0x74, 0x65, 0x78, 0x74, 0x75, 0x72, 0x65, 0x2c, 0x20, 0x76, // re (s_texture, v
	0x5f, 0x74, 0x65, 0x78, 0x63, 0x6f, 0x6f, 0x72, 0x64, 0x30, 0x2e, 0x78, 0x79, 0x29, 0x29, 0x3b, // _texcoord0.xy));
	0x0a, 0x7d, 0x0a, 0x0a, 0x00,                                                                   // .}...
};
