#ifndef MIPPNUMIPIONYIELDSREWEIGHTER_H
#define MIPPNUMIPIONYIELDSREWEIGHTER_H

#include "IInteractionChainReweighting.h"
#include "ParameterTable.h"

namespace NeutrinoFluxReweight{
  
  /*! \class MIPPNumiPionYieldsReweighter
   *  \brief Reweight a chain of interactions that are covered by the NuMI target pi+ and pi- yields measured by MIPP
   */
  class MIPPNumiPionYieldsReweighter : public IInteractionChainReweighting{
  public:  
    /*!
     * The constructor. Note, we pass central value and single universe parameters in this constructor only. There is thus a 1 to 1 correspondence between an instance of this class and a given universe.
     */
    MIPPNumiPionYieldsReweighter(int iuniv, const ParameterTable& cv_pars, const ParameterTable& univ_pars);
    virtual ~MIPPNumiPionYieldsReweighter();
    //! Look through the InteractionChainData input and identify those Interactions that can be reweighted as part of a chain. We return a vector indicating which elements will be assigned a weight by calculateWeight
    virtual std::vector<bool> canReweight(const InteractionChainData& aa);
    //! calculate a weight for this interaction chain given the central value parameters and the parameters for this universe. The weight is something like: f(cv)/f(MC) * f(univ)/f(cv) where cv in this case  corresponds to the best value of the parameter, given the data. If univ_pars=cv_pars then we are calculating a central value weight. Note, canReweight() should be called to determine which elements of the chain are covered by the weight returned by calculateWeight()
    virtual double calculateWeight(const InteractionChainData& aa);   
    const ParameterTable& cvPars;
    const ParameterTable& univPars;

  private:
    int iUniv;
    float prt_no_inter;
    std::vector<float> vbin_data_pip,vbin_data_pim;
  };



  
}
#endif
