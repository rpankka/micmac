/*Header-MicMac-eLiSe-25/06/2007

    MicMac : Multi Image Correspondances par Methodes Automatiques de Correlation
    eLiSe  : ELements of an Image Software Environnement

    www.micmac.ign.fr


    Copyright : Institut Geographique National
    Author : Marc Pierrot Deseilligny
    Contributors : Gregoire Maillet, Didier Boldo.

[1] M. Pierrot-Deseilligny, N. Paparoditis.
    "A multiresolution and optimization-based image matching approach:
    An application to surface reconstruction from SPOT5-HRS stereo imagery."
    In IAPRS vol XXXVI-1/W41 in ISPRS Workshop On Topographic Mapping From Space
    (With Special Emphasis on Small Satellites), Ankara, Turquie, 02-2006.

[2] M. Pierrot-Deseilligny, "MicMac, un lociel de mise en correspondance
    d'images, adapte au contexte geograhique" to appears in
    Bulletin d'information de l'Institut Geographique National, 2007.

Francais :

   MicMac est un logiciel de mise en correspondance d'image adapte
   au contexte de recherche en information geographique. Il s'appuie sur
   la bibliotheque de manipulation d'image eLiSe. Il est distibue sous la
   licences Cecill-B.  Voir en bas de fichier et  http://www.cecill.info.


English :

    MicMac is an open source software specialized in image matching
    for research in geographic information. MicMac is built on the
    eLiSe image library. MicMac is governed by the  "Cecill-B licence".
    See below and http://www.cecill.info.

Header-MicMac-eLiSe-25/06/2007*/

#include "StdAfx.h"
#include "../../../CodeExterne/Poisson/include/PlyFile.h"

static const REAL Eps = 1e-7;

//--------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------
// cTriangle
//--------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------

cTriangle::~cTriangle(){}

void cTriangle::addEdge(int idx)
{
    mTriEdges.push_back(idx);
}

//--------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------

cTriangle::cTriangle(cMesh *aMesh, vector <int> const &idx, int TriIdx):
    mInside(false),
    mTriIdx(TriIdx),
    mTriVertex(idx),
    mTextImIdx(mDefTextImIdx),
    pMesh(aMesh)
{
}

//--------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------

Pt3dr cTriangle::getNormale(bool normalize) const
{
    vector <Pt3dr> vPts;
    getVertexes(vPts);

    if (normalize)
    {
        Pt3dr p1 = vunit(vPts[1]-vPts[0]);
        Pt3dr p2 = vunit(vPts[2]-vPts[0]);
        return vunit(p1^p2);
    }
    else return (vPts[1]-vPts[0])^(vPts[2]-vPts[0]);
}

//--------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------

void cTriangle::getVertexes(vector <Pt3dr> &vList) const
{
    for (unsigned int aK =0; aK < mTriVertex.size(); ++aK)
    {
        vList.push_back(pMesh->getVertex(mTriVertex[aK]));
    }
}

Pt3dr   cTriangle::getVertex(int aK)
{
    //ELISE_ASSERTif (aK < )
    return pMesh->getVertex(mTriVertex[aK]);
}

//--------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------

bool cTriangle::getAttributes(int image_idx, vector <REAL> &ta) const
{
    map <int, vector <REAL> >::const_iterator it;

    it = mAttributes.find(image_idx);
    if (it != mAttributes.end())
    {
        ta = it->second;
        return true;
    }
    else
        return false;
}

//--------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------

void cTriangle::setAttributes(int image_idx, const vector <REAL> &ta)
{
    mAttributes.insert(pair <int, vector <REAL> > (image_idx, ta) );
}

//--------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------

void cTriangle::getVertexesIndexes(int &v1, int &v2, int &v3)
{
    //ELISE_ASSERT
    v1 = mTriVertex[0];
    v2 = mTriVertex[1];
    v3 = mTriVertex[2];
}

//--------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------

REAL cTriangle::computeEnergy(int img_idx)
{
    REAL diff;

    //angle entre la direction de visee de l'image idx et la normale au triangle
    REAL angle0 = (mAttributes.find(img_idx))->second[0];

    REAL min = PI;
    map<int,vector <REAL> >::const_iterator it;
    for (it = mAttributes.begin(); it != mAttributes.end(); it++)
    {
        if (it->first != img_idx)
        {
            diff = abs(angle0 - ((*it).second)[0]);

            if (diff < min) min = diff;
        }
    }

    return PI - min;
}

vector<cTriangle *> cTriangle::getNeighbours()
{
    vector <cTriangle*> res;

    for (unsigned int aK=0; aK<mTriEdges.size(); aK++)
    {
        cEdge edge = pMesh->getEdge(mTriEdges[aK]);

        if (edge.n1() == mTriIdx) res.push_back(pMesh->getTriangle(edge.n2()));
        else if (edge.n2() == mTriIdx) res.push_back(pMesh->getTriangle(edge.n1()));
    }

    return res;
}

void cTriangle::setEdgeIndex(unsigned int pos, int val)
{
    if (mTriEdges.size()>pos)
        mTriEdges[pos] = val;
}

void cTriangle::setVertexIndex(unsigned int pos, int val)
{
    if (mTriVertex.size()>pos)
        mTriVertex[pos] = val;
}

void cTriangle::removeEdge(int idx)
{
    bool found = false;

    //TODO: remove
    for (unsigned int aK=0; aK < mTriEdges.size();++aK)
    {
        //cout << "Edge =  " << mTriEdges[aK] << endl;
        if (mTriEdges[aK] == idx )
        {
            //cout<< "found ****************************" << endl;
            found = true;
        }
    }

    if (found)
    {
        //cout << "removing edge "<< idx << endl;
        mTriEdges.erase(std::remove(mTriEdges.begin(), mTriEdges.end(), idx), mTriEdges.end());
    }
    /*cout << "new index list= "<<endl;

    for (int aK=0; aK< (int) mTriEdges.size();++aK)
        cout << mTriEdges[aK] << " ";

    cout << endl;*/
}

bool cTriangle::operator==( const cTriangle &aTr ) const
{
    return ( (mInside     ==  aTr.mInside )  &&
             (mTriIdx     ==  aTr.mTriIdx)   &&
             (mTriVertex  ==  aTr.mTriVertex) &&
             (mTriEdges   ==  aTr.mTriEdges)  &&
             (mTextImIdx  ==  aTr.mTextImIdx) &&
             (mAttributes ==  aTr.mAttributes)
           );
}
//--------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------
// cMesh
//--------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------

cMesh::~cMesh(){}

//--------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------

Pt3dr cMesh::getVertex(unsigned int idx) const
{
    ELISE_ASSERT(idx < mVertexes.size(), "cMesh3D.cpp cMesh::getPt, out of vertex array");

    return mVertexes[idx];
}

//--------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------

cTriangle* cMesh::getTriangle(unsigned int idx)
{
    ELISE_ASSERT(idx < mTriangles.size(), "cMesh3D.cpp cMesh::getTriangle, out of faces array");

    return &(mTriangles[idx]);
}

//--------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------

cEdge cMesh::getEdge(unsigned int idx) const
{
    ELISE_ASSERT(idx < mEdges.size(), "cMesh3D.cpp cMesh::getEdge, out of edges array");

    return mEdges[idx];
}

//--------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------

static PlyProperty face_props[] =
{
    { "vertex_indices" , PLY_INT , PLY_INT , offsetof(ElPlyFace,vertices) , 1 , PLY_UCHAR, PLY_UCHAR , offsetof(ElPlyFace,nr_vertices) },
};

PlyProperty props[] =
{
    {"x", PLY_FLOAT, PLY_FLOAT, offsetof(sVertex,x), 0, 0, 0, 0},
    {"y", PLY_FLOAT, PLY_FLOAT, offsetof(sVertex,y), 0, 0, 0, 0},
    {"z", PLY_FLOAT, PLY_FLOAT, offsetof(sVertex,z), 0, 0, 0, 0},
};

//--------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------

cMesh::cMesh(const std::string & Filename, bool doAdjacence)
{
    PlyFile * thePlyFile;
    int nelems;
    char **elist;
    int file_type;
    float version;
    int nprops;
    int num_elems;
    char *elem_name;

    thePlyFile = ply_open_for_reading( const_cast<char *>(Filename.c_str()), &nelems, &elist, &file_type, &version);

    ELISE_ASSERT(thePlyFile != NULL, "cMesh3D.cpp: cMesh::cMesh, cannot open ply file for reading");

    for (int i = 0; i < nelems; i++)
    {
        elem_name = elist[i];
        ply_get_element_description (thePlyFile, elem_name, &num_elems, &nprops);

        //printf ("element %s %d\n", elem_name, num_elems);

        if (equal_strings ("vertex", elem_name))
        {
            ply_get_property (thePlyFile, elem_name, &props[0]);
            ply_get_property (thePlyFile, elem_name, &props[1]);
            ply_get_property (thePlyFile, elem_name, &props[2]);

            for (int j = 0; j < num_elems; j++)
            {
                sVertex *vert = (sVertex *) malloc (sizeof(sVertex));

                ply_get_element (thePlyFile, vert);

                //ajout du point
                addPt(Pt3dr(vert->x, vert->y, vert->z));

                //printf ("vertex: %g %g %g\n", vert->x, vert->y, vert->z);
            }
        }
        else if (equal_strings ("face", elem_name))
        {
            ply_get_property ( thePlyFile, elem_name, &face_props[0]);

            for (int j = 0; j < num_elems; j++)
            {
                sFace *theFace = (sFace *) malloc (sizeof (sFace));
                ply_get_element (thePlyFile, theFace);

                vector <int> vIndx;
                for (int aK =0; aK < theFace->nverts; ++aK)
                    vIndx.push_back(theFace->verts[aK]);

                //ajout du triangle
                addTriangle(cTriangle(this, vIndx, j));
            }
        }
    }

    if (doAdjacence) //remplissage du graphe d'adjacence
    {
        int cpt;

        int id0a, id1a, id2a;
        int id0b, id1b, id2b;
        int idc0, idc1; //index des sommets communs
        id0a = id1a = id2a = idc0 = idc1 = -1;
        id0b = id1b = id2b = -2;

        for (int aK = 0; aK < getFacesNumber(); ++aK)
        {
            mTriangles[aK].getVertexesIndexes(id0a, id1a, id2a);

            for (int bK=aK; bK < getFacesNumber(); ++bK)
            {
                mTriangles[bK].getVertexesIndexes(id0b, id1b, id2b);

                cpt = 0;
                if((id0b == id0a)||(id1b == id0a)||(id2b == id0a)) {cpt++; idc0 = id0a;}
                if((id0b == id1a)||(id1b == id1a)||(id2b == id1a))
                {
                    if (cpt) idc1 = id1a;
                    else	 idc0 = id1a;

                    cpt++;
                }
                if((id0b == id2a)||(id1b == id2a)||(id2b == id2a))
                {
                    if (cpt) idc1 = id2a;
                    else	 idc0 = id2a;

                    cpt++;
                }

                if (cpt == 2)
                {
                    #ifdef _DEBUG
                        printf ("found adjacent triangles : %d %d - vertex : %d %d\n", aK, bK, idc0, idc1);
                    #endif

                    addEdge(cEdge(aK, bK, idc0, idc1));
                    int idx = getEdgesNumber() - 1;
                    //cout << "adding edge " << idx << endl;
                    mTriangles[aK].addEdge(idx);
                    mTriangles[bK].addEdge(idx);
                }
            }
        }
    }

    ply_close (thePlyFile);
}

cMesh::cMesh(const cMesh &aMesh):
    mVertexes(aMesh.mVertexes),
    mTriangles(aMesh.mTriangles),
    mEdges(aMesh.mEdges),
    mLambda(aMesh.mLambda)
{}

//--------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------

void cMesh::addPt(const Pt3dr &aPt)
{
    mVertexes.push_back(aPt);
}

//--------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------

void cMesh::addTriangle(const cTriangle &aTri)
{
    mTriangles.push_back(aTri);
}

//--------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------

void cMesh::addEdge(const cEdge &aEdge)
{
    mEdges.push_back(aEdge);
}

void cMesh::removeTriangle(cTriangle &aTri)
{
    vector <int> edges = aTri.getEdgesIndex();
    int index = aTri.getIdx();

   /* cout << "triangle � retirer= " << index << endl;
    cout << "nombre d'edges � retirer =  " << edges.size() << endl;

    for (unsigned int aK=0; aK< edges.size(); aK++)
    {
        cout << "index des edges � retirer = " << edges[aK] << " entre " << mEdges[edges[aK]].n1() << " et " << mEdges[edges[aK]].n2() <<endl;
    }*/

    for (unsigned int aK=0; aK< edges.size(); aK++)
    {
        int edgeIndex = edges[aK];

        cEdge e = mEdges[edgeIndex];

        //cout << "Edge " << edgeIndex << "between " << e.n1() << " "  << e.n2() << endl;

        int idx = -1;
        if (index == e.n1()) idx = e.n2();
        else if (index == e.n2()) idx = e.n1();

        //cout << "looking for edge " << edgeIndex << " between " << e.n1() << " and " << e.n2() << endl;

        if (idx != -1)
        {

            //cout << "idx = " << idx << " / " << mTriangles.size() << endl;
            //cout << "aK = " << aK  << endl;
            mTriangles[idx].removeEdge(edgeIndex);
            //cout << "ok " << endl;

            for (int bK=0;bK < (int) mTriangles.size();bK++ )
            {
                cTriangle aTri = mTriangles[bK];
                vector <int> vIdx = aTri.getEdgesIndex();
                for(unsigned int cK=0; cK< vIdx.size();++cK)
                {
                    if (vIdx[cK] > edgeIndex) mTriangles[bK].setEdgeIndex(cK, vIdx[cK] - 1);
                }
            }

            for (unsigned int bK=aK+1; bK < edges.size();++bK)
            {
                if (edges[bK] >edgeIndex) edges[bK] = edges[bK] -1;
            }

            mEdges.erase(std::remove(mEdges.begin(), mEdges.end(), e), mEdges.end());

        }
        else
            cout << "impossible error !!!!!!" << endl;


    }

    mTriangles.erase(std::remove(mTriangles.begin(), mTriangles.end(), aTri), mTriangles.end());

    for (unsigned int aK=index;aK < mTriangles.size();aK++ )
    {
        mTriangles[aK].setIdx(mTriangles[aK].getIdx()-1);
    }

    for (unsigned int aK=0; aK < mEdges.size();++aK)
    {
        cEdge e = mEdges[aK];
        if (e.n1() > index) mEdges[aK].setN1(e.n1()-1);
        if (e.n2() > index) mEdges[aK].setN2(e.n2()-1);
    }

}

//--------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------

//Calcule et stocke l'angle entre Dir et Triangle (appartenant a TriIdx)
void cMesh::setTrianglesAttribute(int img_idx, Pt3dr Dir, vector <unsigned int> const &aTriIdx)
{
    for (unsigned int aK=0; aK < aTriIdx.size(); aK++)
    {
        cTriangle *aTri = getTriangle(aTriIdx[aK]);

        Pt3dr aNormale = aTri->getNormale(true);

        double cosAngle = scal(Dir, aNormale) / euclid(Dir);

        vector <double> vAttr;
        vAttr.push_back(cosAngle);

        aTri->setAttributes(img_idx, vAttr);
    }
}

//--------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------

void cMesh::setGraph(int img_idx, RGraph &aGraph, vector <int> &aTriInGraph, vector <unsigned int> const &aVisTriIdx)
{
    int id1, id2, pos1, pos2;
    float E0, E1, E2;

    //parcours des aretes du graphe d'adjacence
    for (unsigned int aK=0; aK < mEdges.size(); aK++)
    {
        id1 = mEdges[aK].n1();
        id2 = mEdges[aK].n2();

        //on recherche id1 et id2 parmi les triangles visibles
        if ((find(aVisTriIdx.begin(), aVisTriIdx.end(), id1)!=aVisTriIdx.end()) &&
            (find(aVisTriIdx.begin(), aVisTriIdx.end(), id2)!=aVisTriIdx.end()))
        {
            //on ajoute seulement les triangles qui ne sont pas encore presents dans le graphe
            if (find(aTriInGraph.begin(), aTriInGraph.end(), id1) == aTriInGraph.end())
            {
                aTriInGraph.push_back(id1);
                aGraph.add_node();
            }

            if (find(aTriInGraph.begin(), aTriInGraph.end(), id2) == aTriInGraph.end())
            {
                aTriInGraph.push_back(id2);
                aGraph.add_node();
            }
        }
    }

    cEdge elEdge;

    //creation des aretes et calcul de leur energie
    for (unsigned int aK=0; aK < mEdges.size(); aK++)
    {
        elEdge = mEdges[aK];

        id1 = elEdge.n1();
        id2 = elEdge.n2();

        vector<int>::iterator it1 = find(aTriInGraph.begin(), aTriInGraph.end(), id1);
        vector<int>::iterator it2 = find(aTriInGraph.begin(), aTriInGraph.end(), id2);

        if ( (it1 != aTriInGraph.end()) && (it2 != aTriInGraph.end()) )
        {
            //pos1 = (int) (it1 - aTriInGraph.begin());
            //pos2 = (int) (it2 - aTriInGraph.begin());

            pos1 = (int) distance(aTriInGraph.begin(), it1);
            pos2 = (int) distance(aTriInGraph.begin(), it2);

            //energies de l'arete triangle-source et de l'arete triangle-puit
            cTriangle *Tri1 = getTriangle(id1);
            cTriangle *Tri2 = getTriangle(id2);

            E1 = (float)Tri1->computeEnergy(img_idx);
            E2 = (float)Tri2->computeEnergy(img_idx);

            //if (E1 == 0.f)
            //	aGraph.add_tweights( pos1, 0.f, 1.f );
            //else
            //{
                aGraph.add_tweights( pos1, (float)(mLambda*E1), 0.f );
            //}

            //if (E2 == 0.f)
            //	aGraph.add_tweights( pos2, 0.f, 1.f );
            //else
            //{
                aGraph.add_tweights( pos2, (float)(mLambda*E2), 0.f );
            //}

            //energie de l'arete inter-triangles


            //longueur^2 de l'arete coupee par elEdge
            E0 = (float)square_euclid( getVertex( elEdge.v1() ), getVertex( elEdge.v2() ) );

            aGraph.add_edge(pos1, pos2, E0, E0);
            //aGraph.add_edge(pos1, pos2, 1, 1);
        }
    }

#ifdef oldoldold
    for (unsigned int aK=0; aK < aTriInGraph.size(); aK++)
    {
        cTriangle *Tri = getTriangle(aTriInGraph[aK]);

        E = Tri->computeEnergy(img_idx);
        if (E == 0.f)
            aGraph.add_tweights( aK, 1.f, 0.f );
        else
        {
            aGraph.add_tweights( aK, mLambda*E, 0.f );
            //aGraph.add_tweights( aK, 1.f, 0.f );
            /*if (Tri->isInside())
                aGraph.add_tweights( aK, 0.f, 1.f );
            else
                aGraph.add_tweights( aK, 1.f, 0.f );*/
        }
    }
#endif

}

void cMesh::clean()
{
    int nbFaces = getFacesNumber();
    for(int i=0 ; i < nbFaces; i++)
    {
        cTriangle * Triangle = getTriangle(i);

        if (Triangle->getEdgesNumber() < 3 && !Triangle->isTextured())
        {
            //cout <<"remove triangle " << Triangle->getIdx() << " with " << Triangle->getEdgesNumber() << " edges" << endl;

            //cout <<"sommets = " << Triangle->getVertex(0) << " " << Triangle->getVertex(1) << " " << Triangle->getVertex(2) << endl;

            removeTriangle(*Triangle);
            nbFaces--;
            i--;
        }
        /*else if (!Triangle->isTextured())
            cout << "triangle " << i << " nb edges = " << Triangle->getEdgesNumber() << " textured= " << Triangle->isTextured() << endl;*/
    }

    //suppression des points n'appartenant � aucun triangle
    for(int aK=0; aK < getVertexNumber();++aK)
    {
        bool found = false;
        for(int i=0 ; i < nbFaces; i++)
        {
            int vertex1, vertex2, vertex3;
            getTriangle(i)->getVertexesIndexes(vertex1, vertex2, vertex3);

            if ((aK==vertex1) || (aK==vertex2) || (aK==vertex3))
            {
                found = true;
                break;
            }
        }

        if (!found) //remove this point
        {
            mVertexes.erase(std::remove(mVertexes.begin(), mVertexes.end(), mVertexes[aK]), mVertexes.end());

            for(int i=0 ; i < nbFaces; i++)
            {
                cTriangle * tri= getTriangle(i);
                int vertex1, vertex2, vertex3;
                tri->getVertexesIndexes(vertex1, vertex2, vertex3);

                if (vertex1>aK) tri->setVertexIndex(0, vertex1-1);
                if (vertex2>aK) tri->setVertexIndex(1, vertex2-1);
                if (vertex3>aK) tri->setVertexIndex(2, vertex3-1);

            }
        }
    }
}

std::vector< std::vector <int> > cMesh::getRegions()
{
    int defVal = cTriangle::getDefTextureImgIndex();
    std::set < int > triangleIdxSet;
    std::vector< std::vector <int> > regions;

    for (int aK=0; aK < getFacesNumber();++aK)
    {
        std::vector <int> myList;
        myList.push_back(aK);

        for (unsigned int bK=0; bK < myList.size();++bK)
        {
            cTriangle * Tri = getTriangle(myList[bK]);

            int imgIdx = Tri->getTextureImgIndex();
            if (imgIdx != defVal)
            {
                triangleIdxSet.insert(Tri->getIdx());

                vector <cTriangle *> neighb = Tri->getNeighbours();

                for (unsigned int cK=0; cK < neighb.size();++cK)
                {
                    int triIdx = neighb[cK]->getIdx();
                    if (triangleIdxSet.find(triIdx)== triangleIdxSet.end() &&
                            (neighb[cK]->getTextureImgIndex() == imgIdx))
                    {
                        myList.push_back(triIdx);
                        triangleIdxSet.insert(triIdx);
                    }
                }
            }
        }

        //cout << "myList.size() = " << myList.size() << endl;

        if (myList.size() > 1) //TODO: � retirer si on veut texturer les triangles isol�s
            regions.push_back(myList);
    }

    /*cout << "****************** Resultat *********************" << endl;
    cout << endl;

    for (unsigned int aK=0; aK < regions.size() ; ++aK)
    {
        //first triangle of region aK:
        int triIdx = regions[aK][0];
        cTriangle * Tri = getTriangle(triIdx);

        cout << "one region with " << regions[aK].size() << " triangles, for image " << Tri->getTextureImgIndex() << endl;
    }*/

    return regions;
}

//--------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------
// cZBuf
//--------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------

cZBuf::cZBuf(Pt2di sz, float defVal) :
mSzRes		(sz),
mImTriIdx   (1,1),
mImMask     (1,1),
mRes        (1,1),
mDataRes    (0),
mDpDef      (defVal),
mIdDef      (USHRT_MAX),
mNuage		(0)
{
}

//--------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------

cZBuf::~cZBuf(){}

//--------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------

Im2D_REAL4 cZBuf::BasculerUnMaillage(cMesh const &aMesh)
{
    mRes = Im2D_REAL4(mSzRes.x,mSzRes.y,mDpDef);
    mDataRes = mRes.data();
    mImTriIdx = Im2D_INT4(mSzRes.x,mSzRes.y, mIdDef);

    vector <cTriangle> vTriangles;
    aMesh.getTriangles(vTriangles);

    for (unsigned int aK =0; aK<vTriangles.size();++aK)
    {
        BasculerUnTriangle(vTriangles[aK]);
    }

    return mRes;
}

Im2D_REAL4 cZBuf::BasculerUnMaillage(const cMesh &aMesh, const CamStenope &aCam)
{
    mRes = Im2D_REAL4(mSzRes.x,mSzRes.y,mDpDef);
    mDataRes = mRes.data();
    mImTriIdx = Im2D_INT4(mSzRes.x,mSzRes.y, mIdDef);

    vector <cTriangle> vTriangles;
    aMesh.getTriangles(vTriangles);

    vector <bool> vTrianglesPartiels;  //0= ok 1=partiellement vu ou cach�

    for (unsigned int aK =0; aK<vTriangles.size();++aK)
    {
        vTrianglesPartiels.push_back(false);
    }

    for (unsigned int aK =0; aK<vTriangles.size();++aK)
    {
        cTriangle aTri = vTriangles[aK];

        vector <Pt3dr> Sommets;
        aTri.getVertexes(Sommets);

        if (Sommets.size() == 3)
        {
            Pt2dr A2 = aCam.R3toF2(Sommets[0]);
            Pt2dr B2 = aCam.R3toF2(Sommets[1]);
            Pt2dr C2 = aCam.R3toF2(Sommets[2]);

            Pt2dr AB = B2-A2;
            Pt2dr AC = C2-A2;
            REAL aDet = AB^AC;

            if (aDet!=0)
            {

               /* Pt2di A2i = round_down(A2);
                Pt2di B2i = round_down(B2);
                Pt2di C2i = round_down(C2);

                 //On verifie que le triangle se projete entierement dans l'image
                 //TODO: gerer les triangles de bord
                if (A2i.x < 0 || B2i.x < 0 || C2i.x < 0 || A2i.y < 0 || B2i.y < 0 || C2i.y < 0 || A2i.x >= mSzRes.x || B2i.x >= mSzRes.x || C2i.x >= mSzRes.x || A2i.y >= mSzRes.y  || B2i.y >= mSzRes.y  || C2i.y >= mSzRes.y)
                     return;*/

                Pt3dr center = aCam.OrigineProf();
                REAL zA = euclid(Sommets[0] - center);  //repris de ElNuage3DMaille ProfOfPtE()
                REAL zB = euclid(Sommets[1] - center);
                REAL zC = euclid(Sommets[2] - center);

                Pt2di aP0 = round_down(Inf(A2,Inf(B2,C2)));
                aP0 = Sup(aP0,Pt2di(0,0));
                Pt2di aP1 = round_up(Sup(A2,Sup(B2,C2)));
                aP1 = Inf(aP1,mSzRes-Pt2di(1,1));


                for (INT x=aP0.x ; x<= aP1.x ; x++)
                    for (INT y=aP0.y ; y<= aP1.y ; y++)
                    {
                        Pt2dr AP = Pt2dr(x,y)-A2;

                        // Coordonnees barycentriques de P(x,y)
                        REAL aPdsB = (AP^AC) / aDet;
                        REAL aPdsC = (AB^AP) / aDet;
                        REAL aPdsA = 1 - aPdsB - aPdsC;
                        if ((aPdsA>-Eps) && (aPdsB>-Eps) && (aPdsC>-Eps))
                        {
                            REAL4 aZ = (float) (zA*aPdsA + zB*aPdsB + zC*aPdsC);
                            if (aZ<mDataRes[y][x])
                            {
                                int index = mImTriIdx.GetI(Pt2di(x,y));
                                if (index != mIdDef) vTrianglesPartiels[index] = true;
                                mDataRes[y][x] = aZ;
                                mImTriIdx.SetI(Pt2di(x,y),aTri.getIdx());
                            }
                        }
                    }
            }
        }
    }

    //on enleve les triangles partiellement vus
    for(int aK=0; aK < mSzRes.x; aK++)
        for (int bK=0; bK < mSzRes.y; bK++)
        {
            int index = mImTriIdx.GetI(Pt2di(aK,bK));
            if (vTrianglesPartiels[index])
            {
                mDataRes[bK][aK] = mDpDef;
                mImTriIdx.SetI(Pt2di(aK,bK),USHRT_MAX);
            }
            else if ((index != mIdDef) && (find(vTri.begin(), vTri.end(), index)==vTri.end())) vTri.push_back(index);
        }

    return mRes;
}

//--------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------

void cZBuf::BasculerUnTriangle(cTriangle &aTri, bool doMask)
{
    vector <Pt3dr> Sommets;
    aTri.getVertexes(Sommets);

    if (Sommets.size() == 3 )
    {
        //Projection du terrain vers l'image
        Pt3dr A3 = mNuage->Euclid2ProfAndIndex(Sommets[0]);
        Pt3dr B3 = mNuage->Euclid2ProfAndIndex(Sommets[1]);
        Pt3dr C3 = mNuage->Euclid2ProfAndIndex(Sommets[2]);

        Pt2dr A2(A3.x, A3.y);
        Pt2dr B2(B3.x, B3.y);
        Pt2dr C2(C3.x, C3.y);

        Pt2dr AB = B2-A2;
        Pt2dr AC = C2-A2;
        REAL aDet = AB^AC;

        if (aDet==0) return;

        Pt2di A2i = round_down(A2);
        Pt2di B2i = round_down(B2);
        Pt2di C2i = round_down(C2);

         //On verifie que le triangle se projete entierement dans l'image
         //TODO: gerer les triangles de bord
        if (A2i.x < 0 || B2i.x < 0 || C2i.x < 0 || A2i.y < 0 || B2i.y < 0 || C2i.y < 0 || A2i.x >= mSzRes.x || B2i.x >= mSzRes.x || C2i.x >= mSzRes.x || A2i.y >= mSzRes.y  || B2i.y >= mSzRes.y  || C2i.y >= mSzRes.y)
             return;

        REAL zA = A3.z;
        REAL zB = B3.z;
        REAL zC = C3.z;

        Pt2di aP0 = round_down(Inf(A2,Inf(B2,C2)));
        aP0 = Sup(aP0,Pt2di(0,0));
        Pt2di aP1 = round_up(Sup(A2,Sup(B2,C2)));
        aP1 = Inf(aP1,mSzRes-Pt2di(1,1));

        if (doMask)
        {
            for (INT x=aP0.x ; x<= aP1.x ; x++)
                for (INT y=aP0.y ; y<= aP1.y ; y++)
                {
                    Pt2dr AP = Pt2dr(x,y)-A2;

                    // Coordonnees barycentriques de P(x,y)
                    REAL aPdsB = (AP^AC) / aDet;
                    REAL aPdsC = (AB^AP) / aDet;
                    REAL aPdsA = 1 - aPdsB - aPdsC;
                    if ((aPdsA>-Eps) && (aPdsB>-Eps) && (aPdsC>-Eps))
                    {
                        mImMask.set(x, y, 1);
                    }
                }
        }
        else
        {
            for (INT x=aP0.x ; x<= aP1.x ; x++)
                for (INT y=aP0.y ; y<= aP1.y ; y++)
                {
                    Pt2dr AP = Pt2dr(x,y)-A2;

                    // Coordonnees barycentriques de P(x,y)
                    REAL aPdsB = (AP^AC) / aDet;
                    REAL aPdsC = (AB^AP) / aDet;
                    REAL aPdsA = 1 - aPdsB - aPdsC;
                    if ((aPdsA>-Eps) && (aPdsB>-Eps) && (aPdsC>-Eps))
                    {
                        REAL4 aZ = (float) (zA*aPdsA + zB*aPdsB + zC*aPdsC);
                        if (aZ>mDataRes[y][x])
                        {
                            mDataRes[y][x] = aZ;
                            mImTriIdx.SetI(Pt2di(x,y),aTri.getIdx());
                        }
                    }
                }
        }
    }
}

//--------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------

void cZBuf::ComputeVisibleTrianglesIndexes()
{
    for (int aK=0; aK < mSzRes.x; aK++)
    {
        for (int bK=0; bK < mSzRes.y; bK++)
        {
            int Idx = mImTriIdx.Val(aK,bK);

            if ((Idx != mIdDef) && (find(vTri.begin(), vTri.end(), Idx)==vTri.end())) vTri.push_back(Idx);
        }
    }
}

//--------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------

Im2D_BIN cZBuf::ComputeMask(int img_idx, cMesh &aMesh)
{
    mImMask = Im2D_BIN (mSzRes.x, mSzRes.y, 0);

    #ifdef _DEBUG
        printf ("nb triangles : %d\n", vTri.size());
    #endif

    for (unsigned int aK=0; aK < vTri.size(); aK++)
    {
        cTriangle *aTri = aMesh.getTriangle(vTri[aK]);

        if (aTri->hasAttributes())
        {
            REAL bestAngle = mMaxAngle;
            int  bestImage = -1;
            REAL Angle;

            map<int, vector <REAL> > aMap = aTri->getAttributesMap();

            map<int, vector <REAL> >::const_iterator it;
            for (it = aMap.begin();it != aMap.end(); it++)
            {
                vector <REAL> vAttr = it->second;

                if (vAttr[0] < 0.f) Angle = PI - acos(vAttr[0]);
                else Angle = acos(vAttr[0]);

                if (Angle < bestAngle)
                {
                    bestAngle = Angle;
                    bestImage = it->first;
                }
            }

            if ((bestAngle < mMaxAngle) && (bestImage == img_idx))
            //if (bestAngle < mMaxAngle)
            {
                BasculerUnTriangle(*aTri, true);
                aTri->setInside();
            }
        }
    }

    return mImMask;
}

//--------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------

Im2D_BIN cZBuf::ComputeMask(vector <int> const &TriInGraph, RGraph &aGraph, cMesh &aMesh)
{
    mImMask = Im2D_BIN (mSzRes.x, mSzRes.y, 0);

    /*printf(" taille de TriIngraph :  %d", TriInGraph.size());
    printf(" aGraph.get_node_num  :  %d", aGraph.get_node_num());*/

    for (unsigned int aK=0; aK < TriInGraph.size(); aK++)
    {
        if (aGraph.what_segment(aK) == RGraph::SOURCE) BasculerUnTriangle(*(aMesh.getTriangle(TriInGraph[aK])), true);
    }

    return mImMask;
}

//--------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------
// cEdge
//--------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------

cEdge::cEdge()
{
    mNode1 = -1;
    mNode2 = -1;
    mV1	   = -1;
    mV2    = -1;
}

cEdge::~cEdge(){}

bool cEdge::operator==(const cEdge & e) const
{
    return ((mNode1 == e.mNode1) &&
            (mNode2 == e.mNode2) &&
            (mV1    == e.mV1)    &&
            (mV2    == e.mV2)
            );
}
