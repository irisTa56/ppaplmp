/* ---------------------------------------------------------------------
AddChildIDs: stands for Adder for Child IDs (such as atom-ids in the
case of molecules).

create: 2018/08/19 by Takayuki Kobayashi
--------------------------------------------------------------------- */

#include "add_child_ids.h"
#include "utils.h"

/* ------------------------------------------------------------------ */

AddChildIDs::AddChildIDs(
  ShPtr<GenElement> elem,
  const Str &child_name_,
  const Str &key_for_parent_id_)
{
  ext_generator = elem;
  child_name = child_name_;
  key_for_parent_id = key_for_parent_id_;
}

/* ------------------------------------------------------------------ */

void AddChildIDs::compute_impl(
  Json &data,
  Set<Str> &datakeys)
{
  auto gen_children = ext_generator->get_element();

  check_keys(gen_children, {"id", key_for_parent_id});
  check_key(datakeys, "id");

  auto key_for_child_ids = child_name + "-ids";

  if (check_containment<Str>(datakeys, key_for_child_ids))
  {
    runtime_error(
      "AddChildIDs cannot overwrite '" + key_for_child_ids + "'");
  }

  auto id2index = get_map_to_index(data, "id");

  for (const auto &child : gen_children->get_data())
  {
    auto mol_index = id2index[child[key_for_parent_id]];
    data[mol_index][key_for_child_ids].push_back(child["id"]);
  }

  datakeys.insert(key_for_child_ids);
}
