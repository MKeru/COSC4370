
#version 330 core
out vec4 color;

in vec2 UV;
uniform sampler2D myTextureSampler;

void main()
{
    vec2 myUV = UV;
    // TODO: pub with your code...
    for (int i = 0; i < 36; i++) {
      if (myUV.y > 0.33) {
        //invert
        myUV.y = 1.0 - myUV.y;
      }
    }
    color = texture(myTextureSampler, vec2(UV.x, myUV.y));
}
