#pragma once


#include <vector>


class FloatingMeasure;


class FloatingMeasureSelector
{
private:
   std::vector<FloatingMeasure *> *pool;

public:
   FloatingMeasureSelector(std::vector<FloatingMeasure *> *pool);
   ~FloatingMeasureSelector();
};


