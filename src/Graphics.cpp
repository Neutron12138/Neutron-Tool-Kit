#ifndef __NEUTRON_GRAPHICS_CPP__
#define __NEUTRON_GRAPHICS_CPP__

#include "Graphics.cpp"

#include "Graphics/GL.cpp"
#include "Graphics/GLObject.cpp"
#include "Graphics/Bindable.cpp"
#include "Graphics/Renderable.cpp"

#include "Graphics/Shade/Shader.cpp"
#include "Graphics/Shade/Program.cpp"
#include "Graphics/Shade/UniformBinder.cpp"
#include "Graphics/Shade/UniformDescriber.cpp"

#include "Graphics/Buffer/BufferObject.cpp"
#include "Graphics/Buffer/VertexBufferObject.cpp"

#include "Graphics/Vertex/VertexArrayObject.cpp"
#include "Graphics/Vertex/Sprite.cpp"
#include "Graphics/Vertex/PrimitiveSprite.cpp"
#include "Graphics/Vertex/Sprite2D.cpp"
#include "Graphics/Vertex/PrimitiveSprite2D.cpp"

#include "Graphics/Matrix/MatrixHolder.cpp"
#include "Graphics/Matrix/Transform.cpp"
#include "Graphics/Matrix/View.cpp"
#include "Graphics/Matrix/Projection.cpp"
#include "Graphics/Matrix/PerspectiveProjection.cpp"
#include "Graphics/Matrix/Transform2D.cpp"
#include "Graphics/Matrix/Trackable.cpp"
#include "Graphics/Matrix/TrackingView.cpp"
#include "Graphics/Matrix/OrbitView.cpp"
#include "Graphics/Matrix/Camera.cpp"
#include "Graphics/Matrix/RectProjection.cpp"
#include "Graphics/Matrix/OrthoProjection.cpp"
#include "Graphics/Matrix/FrustumProjection.cpp"
#include "Graphics/Matrix/DefaultCamera.cpp"

#include "Graphics/Model/Model.cpp"
#include "Graphics/Model/ModelBuilder.cpp"
#include "Graphics/Model/ObjLoader.cpp"

#include "Graphics/Material/Material.cpp"
#include "Graphics/Material/MtlLoader.cpp"

#include "Graphics/Texture/Texture.cpp"
#include "Graphics/Texture/Texture2D.cpp"

#include "Graphics/Text/Glyph.cpp"
#include "Graphics/Text/Font.cpp"
#include "Graphics/Text/TrueTypeFont.cpp"
#include "Graphics/Text/GlyphCollection.cpp"

#include "Graphics/Renderer/BaseRenderer.cpp"
#include "Graphics/Renderer/BaseShape.cpp"
#include "Graphics/Renderer/Shapes/PointShape.cpp"
#include "Graphics/Renderer/Shapes/LineShape.cpp"
#include "Graphics/Renderer/Shapes/PolygonShape.cpp"
#include "Graphics/Renderer/Shapes/RectangleShape.cpp"
#include "Graphics/Renderer/Text.cpp"
#include "Graphics/Renderer/Shapes/RegularPolygonShape.cpp"
#include "Graphics/Renderer/Shapes/CircleShape.cpp"
#include "Graphics/Renderer/BaseSpatial.cpp"
#include "Graphics/Renderer/Spatial/CuboidSpatial.cpp"

#endif