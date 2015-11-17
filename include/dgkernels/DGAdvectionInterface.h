/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*           (c) 2010 Battelle Energy Alliance, LLC             */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*          Prepared by Battelle Energy Alliance, LLC           */
/*            Under Contract No. DE-AC07-05ID14517              */
/*            With the U. S. Department of Energy               */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#ifndef DGADVECTIONINTERFACE_H
#define DGADVECTIONINTERFACE_H

#include "DGInterface.h"

//Forward Declarations
class DGAdvectionInterface;

template<>
InputParameters validParams<DGAdvectionInterface>();

/**
 * DG kernel for interfacing advection on adjacent blocks
 */
class DGAdvectionInterface : public DGInterface
{
public:
  DGAdvectionInterface(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual(Moose::DGResidualType type);
  virtual Real computeQpJacobian(Moose::DGJacobianType type);

  MooseVariable & _potential_var;
  MooseVariable & _potential_neighbor_var;
  VariableGradient & _grad_potential;
  VariableGradient & _grad_potential_neighbor;

  const MaterialProperty<Real> & _mu;
  const MaterialProperty<Real> & _mu_neighbor;
  const MaterialProperty<Real> & _sgn;
  const MaterialProperty<Real> & _sgn_neighbor;
};

#endif
