#ifndef __ASSETSTORE_H__
#define __ASSETSTORE_H__


class
AsssetStore
{
  HashMap*   loadedTextures;

public:

  void
  LoadTexture(char* name, char* path);
  
  SDL_Texture*
  GetTexture(char* name);
};


#endif // __ASSETSTORE_H__
