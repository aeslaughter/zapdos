#ifndef CURRENT_H
#define CURRENT_H

#include "AuxKernel.h"

class Current;

template<>
InputParameters validParams<Current>();

class Current : public AuxKernel
{
public:
  Current(const InputParameters & parameters);

  virtual ~Current() {}
  virtual Real computeValue();

protected:
  MooseVariable & _density_var;
  VariableValue & _density_log;
  VariableGradient & _grad_density_log;
  VariableGradient & _grad_potential;
  const MaterialProperty<Real> & _mu;
  const MaterialProperty<Real> & _sgn;
  const MaterialProperty<Real> & _diff;
};

#endif //CURRENT_H
