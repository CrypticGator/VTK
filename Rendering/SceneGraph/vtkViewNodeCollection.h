/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkViewNodeCollection.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkViewNodeCollection - collection of view nodes
// .SECTION Description
// vtk centric collection of vtkViewNodes

#ifndef vtkViewNodeCollection_h
#define vtkViewNodeCollection_h

#include "vtkRenderingSceneGraphModule.h" // For export macro
#include "vtkCollection.h"

class vtkViewNode;

class VTKRENDERINGSCENEGRAPH_EXPORT vtkViewNodeCollection :
  public vtkCollection
{
public:
  static vtkViewNodeCollection* New();
  vtkTypeMacro(vtkViewNodeCollection, vtkCollection);
  void PrintSelf(ostream& os, vtkIndent indent);

  // Description:
  // Add a ViewNode to the list.
  void AddItem(vtkViewNode *a);

  // Description:
  // Get the next ViewNode in the list. NULL is returned when the collection is
  // exhausted.
  vtkViewNode *GetNextItem();

  // Description:
  // Reentrant safe way to get an object in a collection. Just pass the
  // same cookie back and forth.
  vtkViewNode *GetNextViewNode(vtkCollectionSimpleIterator &cookie);

  // Description:
  // Return true only if we have viewnode for obj.
  bool IsRenderablePresent(vtkObject *obj);

protected:
  vtkViewNodeCollection() {};
  ~vtkViewNodeCollection() {};

private:
  // hide the standard AddItem from the user and the compiler.
  void AddItem(vtkObject *o)
    { this->vtkCollection::AddItem(o); }

  vtkViewNodeCollection(const vtkViewNodeCollection&); // Not implemented.
  void operator=(const vtkViewNodeCollection&); // Not implemented.
};

#endif
