#ifndef _CAMERA_H_
#define _CAMERA_H_


typedef struct CameraTag {
    float x;
    float y;
    float zoom;
} Camera;


Camera *Camera_new(void);
void Camera_set_zoom(Camera *self, float zoom);

#endif
