#ifndef PYBIND_PRO_DISTANCE_IN_MOLECULE_H
#define PYBIND_PRO_DISTANCE_IN_MOLECULE_H

#include <processors/pro_distance_in_molecule.h>
#include <pybind/processors/processor.h>

static void pybind_pro_distance_in_molecule(py::module &m)
{
  py::class_<ProDistanceInMolecule,PyProcessor<ProDistanceInMolecule>,Processor,ShPtr<ProDistanceInMolecule>>(m, "ProDistanceInMolecule")
    .def(py::init<const ShPtr<Element> &,const ShPtr<Element> &>())
    .def(py::init<const Vec<std::pair<ShPtr<Element>,ShPtr<Element>>> &>())
    .def("set_indices", &ProDistanceInMolecule::set_indices)
    .def("set_moltype", &ProDistanceInMolecule::set_moltype)
    .def(
      "compute_sqrt", &ProDistanceInMolecule::compute_sqrt,
      py::arg("do_sqrt_") = true)
    .def(
      "get_distance_array", &ProDistanceInMolecule::get_distance_array,
      py::return_value_policy::reference_internal)
    .def(
      "get_distance2_array", &ProDistanceInMolecule::get_distance2_array,
      py::return_value_policy::reference_internal);
}

#endif