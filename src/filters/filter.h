/*!
  @file src/filters/filter.h
  @brief This file has a definition of Filter class,
  which is a subclass of Updater class.
  @author Takayuki Kobayashi
  @date 2018/06/30
*/

#ifndef FILTER_H
#define FILTER_H

#include <core/updater.h>

/*!
  @brief Filter removes elements from array Element::data
  if the elements fail user-defined criteria.

  This class inherits Updater class and overrides Updater::compute.
  This class is an abstract class and has a pure virtual function,
  Filter::compute_impl.

  Name of subclass of this class should be prefixed by *Fil*.
  Note that Filter do nothing for non-array Element::data.
*/
class Filter : public Updater {
 public:
  using Updater::Updater;
  virtual ~Filter() = default;
  /*!
    @brief Filter elements from array Element::data given
    as a mutable reference.

    @param elem
      Shared pointer to an Element object to be filtered.

    @param dataid
      A constant integer copied from Element::dataid.

    @return None.

    This method checks if `dataid` is in #dataid_blacklist.
    If it is not in the blacklist, this method passes `data`
    to Filter::compute_impl. Each element in the array `data` remains
    unchanged. Note that actual filtering process is conducted by
    Filter::compute_impl orveridden in subclasses of this class.
  */
  virtual void compute(
    const ElPtr &elem,
    const int dataid) override;
};

#endif