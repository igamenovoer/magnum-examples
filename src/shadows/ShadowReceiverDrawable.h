/*
    This file is part of Magnum.

    Original authors — credit is appreciated but not required:

        2010, 2011, 2012, 2013, 2014, 2015, 2016 —
            Vladimír Vondruš <mosra@centrum.cz>
        2016 — Bill Robinson <airbaggins@gmail.com>

    This is free and unencumbered software released into the public domain.

    Anyone is free to copy, modify, publish, use, compile, sell, or distribute
    this software, either in source code form or as a compiled binary, for any
    purpose, commercial or non-commercial, and by any means.

    In jurisdictions that recognize copyright laws, the author or authors of
    this software dedicate any and all copyright interest in the software to
    the public domain. We make this dedication for the benefit of the public
    at large and to the detriment of our heirs and successors. We intend this
    dedication to be an overt act of relinquishment in perpetuity of all
    present and future rights to this software under copyright law.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
    THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
    IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
    CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#pragma once
#include <Magnum/SceneGraph/Drawable.h>
#include <Magnum/Mesh.h>

class ShadowReceiverShader;
class ShadowLight;

/// Drawable that should render shadows cast by casters
class ShadowReceiverDrawable : public Magnum::SceneGraph::Drawable3D {
public:
    ShadowReceiverDrawable(Magnum::SceneGraph::AbstractObject3D &object,
                           Magnum::SceneGraph::DrawableGroup3D *drawables);

    virtual void draw(const Magnum::Matrix4 &transformationMatrix,
                      Magnum::SceneGraph::Camera3D &camera) override;

    void setMesh(Magnum::Mesh *mesh) {
        this->mesh = mesh;
    }

    void setShader(ShadowReceiverShader* shader) {
        this->shader = shader;
    }

private:
    Magnum::Mesh* mesh;
    ShadowReceiverShader* shader;
};


