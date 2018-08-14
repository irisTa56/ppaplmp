/* ---------------------------------------------------------------------
Updater: is an abstract class to update data held by Generator.

create: 2018/06/29 by Takayuki Kobayashi
--------------------------------------------------------------------- */

#ifndef UPDATER_H
#define UPDATER_H

#include "generator.h"

class Updater {
  Set<int> dataid_blacklist;
  omp_lock_t omp_lock;
 protected:
  ShPtr<Generator> ext_generator;
  virtual void compute_impl(Json &, Set<Str> &) = 0;
  const bool check_blacklist(int);
 public:
  Updater() { omp_init_lock(&omp_lock); }
  virtual ~Updater() = default;
  virtual void compute(Json &, Set<Str> &, int) = 0;
  void remove_from_blacklist(int);
  ShPtr<Generator> get_ext_generator();
};

/* ------------------------------------------------------------------ */
// for pybind11

// trampoline class to bind Python
template <class UPD = Updater>
class PyUpdater : public UPD {
 protected:
  void compute_impl(Json &data) override
  {
    PYBIND11_OVERLOAD_PURE(void, UPD, compute_impl, data);
  }
 public:
  using UPD::UPD;
  void compute(Json &data, int dataid) override
  {
    PYBIND11_OVERLOAD_PURE(void, UPD, compute, data, dataid);
  }
};

#endif