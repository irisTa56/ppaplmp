/* ---------------------------------------------------------------------
ProData: stands for Processor which returns Data itself.

create: 2018/06/22 by Takayuki Kobayashi
--------------------------------------------------------------------- */

#ifndef PRO_DATA_H
#define PRO_DATA_H

#include "processor.h"

class ProData : public Processor {
  List<Str> selected_keys;
  List<Json> results;
 protected:
  virtual void run_impl(
    int index) override;
 public:
  ProData(
    ShPtr<GenElement> elem);
  ProData(
    List<ShPtr<GenElement>> elems);
  virtual ~ProData() = default;
  virtual void prepare() override;
  void select(
    py::args);
  const List<Json> &get_results();
};

/* ------------------------------------------------------------------ */
// for pybind11

static void pybind_pro_data(py::module &m)
{
  py::class_<ProData,PyProcessor<ProData>,Processor,ShPtr<ProData>>(m, "ProData")
    .def(py::init<ShPtr<GenElement>>())
    .def(py::init<List<ShPtr<GenElement>>>())
    .def("select", &ProData::select)
    .def("get_results", &ProData::get_results);
}

#endif
