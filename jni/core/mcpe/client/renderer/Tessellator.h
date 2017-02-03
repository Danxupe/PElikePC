#pragma once

#include "../MemoryTracker.h"
#include "mcpe/util/Vec2.h"

class Color;
class PrimitiveMode;
class MaterialPtr;

class Tessellator : public MemoryTracker
{
public:
	static Tessellator instance;
public:
	virtual ~Tessellator();
	virtual void getStats() const;
public:
	Tessellator(MemoryTracker*);
	void init();
	//void draw(mce::MaterialPtr const&, mce::TexturePtr const&);
	void begin(int);
	void color(int);
	void vertexUV(float, float, float, float, float);
	void voidBeginAndEndCalls(bool);
	void end(char const*, bool);
	//void draw(mce::MaterialPtr const&, mce::TexturePtr const&, mce::TexturePtr const&);
	void color(Color const&);
	void addOffset(float, float, float);
	void beginIndices(int);
	void quad(unsigned int, unsigned int, unsigned int, unsigned int);
	//void begin(mce::PrimitiveMode, int);
	void vertex(float, float, float);
	void vertexUV(Vec3 const&, float, float);
	void draw(mce::MaterialPtr const&);
	void colorABGR(int);
	void triangle(unsigned int, unsigned int, unsigned int);
	void vertex(Vec3 const&);
	void normal(Vec3 const&);
	void quadFacing(signed char);
	void resetScale();
	void tex(Vec2 const&);
	void tex1(Vec2 const&);
	void color(float, float, float, float);
	void normal(float, float, float);
	void scale3d(float, float, float);
	void addOffset(Vec3 const&);
	void setOffset(Vec3 const&);
	void setOffset(float, float, float);
	void isTessellating() const;
	void trim();
	void getVertexCount() const;
	void tilt();
	void resetTilt();
	void color(int, int);
	void addRotationOffset(float, Vec3 const&);
	void setRotationOffset(float, Vec3 const&);
	void quad(unsigned int, bool);
	void tex1(float, float);
	void noColor();
	void enableColor();
	void _allocateIndices(int);
	void tex(float, float);
	void _tex(Vec2 const&, int);
	void quad(bool);
	void tex2(Vec2 const&);
	void tex2(float, float);
	void clear();
	void color(unsigned char, unsigned char, unsigned char, unsigned char);
	void color(int, int, int, int);
	void cancel();
	void scale2d(float, float);
	void getColor();
	void getByteSize() const;
	void getPolygonCount() const;
	void getVertexFormat() const;
};
