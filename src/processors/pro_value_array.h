/* ---------------------------------------------------------------------
ProValueArray: stands for Processor returning selected (double) Values
contained in Arrays.

create: 2018/07/16 by Takayuki Kobayashi
--------------------------------------------------------------------- */

#ifndef PRO_VALUE_ARRAY_H
#define PRO_VALUE_ARRAY_H

#include <processors/processor.h>

class ProValueArray : public Processor {
  List<Str> selected_keys;
  Dict<Str,ArrayXXd> results;
  Dict<Str,List<RowArrayXd>> results_trajs;
 protected:
  virtual void run_impl(
    int index) override;
 public:
  ProValueArray(
    ShPtr<Element> elem);
  ProValueArray(
    List<ShPtr<Element>> elems);
  virtual ~ProValueArray() = default;
  virtual void prepare() override;
  virtual void finish() override;
  void select(
    py::args args);
  const Dict<Str,ArrayXXd> &get_results();
};

#endif