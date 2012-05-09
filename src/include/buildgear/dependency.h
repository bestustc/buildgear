#ifndef DEPENDENCY_H
#define DEPENDENCY_H

#include "buildgear/buildfiles.h"
#include "buildgear/dependency.h"

using namespace std;

class CDependency
{
	public:
      void ShowDownloadOrder(void);
      void ShowBuildOrder(void);
      void ResolveSequentialBuildOrder(string name,
                   list<CBuildFile*> *buildfiles);
      void ResolveParallelBuildOrder(void);
      void ShowDependencyCircleSVG(string filename);
      list<CBuildFile*> resolved;
      list<CBuildFile*> unresolved;
      list<CBuildFile*> build_order;
      list<CBuildFile*> parallel_build_order;
      list<CBuildFile*> download_order;
   private:
      void ResolveDependency(CBuildFile *buildfile,
                   list<CBuildFile*> *resolved,
                   list<CBuildFile*> *unresolved);
      int setDepth(CBuildFile *buildfile, int depth);
};

#endif