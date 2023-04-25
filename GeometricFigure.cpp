#include "GeometricFigure.h"
#include "Expression.h"
#include <iostream>

/* ------------   ALREADY IMPLEMENTED   ------------ */
float FlatGeometricFigure::Area() const
{
    return this->m_area->Value();
}

/* ------------   ALREADY IMPLEMENTED   ------------ */
FlatGeometricFigure::~FlatGeometricFigure()
{
    delete this->m_area;
}

/* ------------   ALREADY IMPLEMENTED   ------------ */
void FlatGeometricFigure::Info(std::ostream& out) const
{
	out << "Area: " << *m_area;
}

/* ------------   ALREADY IMPLEMENTED   ------------ */
std::ostream& operator<<(std::ostream& out, const FlatGeometricFigure& figure)
{
    figure.Info(out); return out;
}

/* ------------   ALREADY IMPLEMENTED   ------------ */
float SpatialGeometricFigure::Volume() const
{
    return this->m_volume->Value();
}

/* ------------   ALREADY IMPLEMENTED   ------------ */
SpatialGeometricFigure::~SpatialGeometricFigure()
{
    delete this->m_volume;
}

/* ------------   ALREADY IMPLEMENTED   ------------ */
void SpatialGeometricFigure::Info(std::ostream& out) const
{
	FlatGeometricFigure::Info(out); out << " Volume: " << *m_volume;
}

/* ------------   ALREADY IMPLEMENTED   ------------ */
Parallelogram::Parallelogram(float aValue, float hValue)
{	
    this->m_area = new AreaFormulaParallelogram(aValue, hValue);
}

/* ------------   ALREADY IMPLEMENTED   ------------ */
void Parallelogram::Info(std::ostream& out) const
{
    out << "Parallelogram: "; FlatGeometricFigure::Info(out);
}

/* ------------   STAGE_3 (3Pts)   ------------ */

Rectangle::Rectangle(float aValue, float hValue): Parallelogram(aValue, hValue)
{	
    // this->m_area = new AreaFormulaParallelogram(aValue, hValue);
}

void Rectangle::Info(std::ostream& out) const
{
    out << "Rectangle: "; FlatGeometricFigure::Info(out);
}

/* ------------   STAGE_3 (3Pts)   ------------ */
Square::Square(float aValue): Rectangle(aValue, aValue)
{	

}

void Square::Info(std::ostream& out) const
{
    out << "Square: "; FlatGeometricFigure::Info(out);
}

/* ------------   STAGE_3 (3Pts)   ------------ */
Triangle::Triangle(float aValue, float hValue)
{	
    this->m_area = new AreaFormulaTriangle(aValue, hValue);
}

void Triangle::Info(std::ostream& out) const
{
    out << "Triangle: "; FlatGeometricFigure::Info(out);
}
/* ------------   STAGE_3 (3Pts)   ------------ */
Circle::Circle(float rValue) {
    this->m_area = new AreaFormulaCircle(rValue);
}
void Circle::Info(std::ostream& out) const
{
    out << "Circle: "; FlatGeometricFigure::Info(out);
}

/* ------------   STAGE_3 (3Pts)   ------------ */

/* ------------   STAGE_3 (3Pts)   ------------ */

/* ------------   STAGE_3 (3Pts)   ------------ */

/* ------------   STAGE_3 (3Pts)   ------------ */

/* ------------   ALREADY IMPLEMENTED   ------------ */
Cube::Cube(float aValue)
{
    this->m_area = new AreaFormulaParallelogram(aValue, aValue);
	this->m_volume = new VolumeFormulaPrism(this->m_area, aValue);
}

/* ------------   ALREADY IMPLEMENTED   ------------ */
void Cube::Info(std::ostream& out) const
{
    out << "Cube - "; SpatialGeometricFigure::Info(out);
}

/* ------------   STAGE_3 (3Pts)   ------------ */

Tetrahedron::Tetrahedron(float bValue, float hValue, float cValue)
{
    this->m_area = new AreaFormulaTriangle(bValue, hValue);
    std::cout << m_area->Value() << std::endl;
    std::cout << m_area->Value() << std::endl;
	this->m_volume = new VolumeFormulaPyramid(this->m_area, cValue);
}

void Tetrahedron::Info(std::ostream& out) const
{
    out << "Tetrahedron - "; SpatialGeometricFigure::Info(out);
}


/* ------------   STAGE_3 (3Pts)   ------------ */
Cone::Cone(float rValue, float hValue)
{
    this->m_area = new AreaFormulaCircle(rValue);
	this->m_volume = new VolumeFormulaPyramid(this->m_area, hValue);
}

void Cone::Info(std::ostream& out) const
{
    out << "Cone - "; SpatialGeometricFigure::Info(out);
}

/* ------------   STAGE_3 (3Pts)   ------------ */

/* ------------   STAGE_3 (3Pts)   ------------ */
