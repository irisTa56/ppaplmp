/* ---------------------------------------------------------------------
Invoker: is an abstract class to execute processes.

create: 2018/06/23 by Takayuki Kobayashi
--------------------------------------------------------------------- */

#include "invoker.h"
#include "utils.h"

/* ------------------------------------------------------------------ */

Invoker::Invoker(std::shared_ptr<Processor> proc)
{
  processors.push_back(proc);
  n_processors = processors.size();
}

/* ------------------------------------------------------------------ */

Invoker::Invoker(std::vector<std::shared_ptr<Processor>> procs)
{
  processors = procs;
  n_processors = processors.size();
}

/* ------------------------------------------------------------------ */

void Invoker::execute()
{
  for (auto p : processors)
  {
    p->prepare();
  }

  execute_impl();

  for (auto p : processors)
  {
    p->finish();
  }
}