#ifndef MIPPNUMIKAONYIELDSREWEIGHTER_H
#define MIPPNUMIKAONYIELDSREWEIGHTER_H

#include "IInteractionChainReweighting.h"

#if defined __clang__
  #pragma clang diagnostic push
  #pragma clang diagnostic ignored "-Wunused-private-field"
#endif
namespace NeutrinoFluxReweight{
  
  /*! \class MIPPNumiKaonYieldsReweighter
   *  \brief Reweight a chain of interactions that are covered by the NuMI target K/pi ratios measured by MIPP
   */
  class MIPPNumiKaonYieldsReweighter : public IInteractionChainReweighting{
  public:  
    /*!
     * The constructor. Note, we pass central value and single universe parameters in this constructor only. There is thus a 1 to 1 correspondence between an instance of this class and a given universe.
     */
    MIPPNumiKaonYieldsReweighter(int iuniv, const ParameterTable& cv_pars, const ParameterTable& univ_pars);
    virtual ~MIPPNumiKaonYieldsReweighter();
    //! Look through the InteractionChainData input and identify those Interactions that can be reweighted as part of a chain. We return a vector indicating which elements will be assigned a weight by calculateWeight
    virtual std::vector<bool> canReweight(const InteractionChainData& aa);
    //! calculate a weight for this interaction chain given the central value parameters and the parameters for this universe. The weight is something like: f(cv)/f(MC) * f(univ)/f(cv) where cv in this case  corresponds to the best value of the parameter, given the data. If univ_pars=cv_pars then we are calculating a central value weight. Note, canReweight() should be called to determine which elements of the chain are covered by the weight returned by calculateWeight()
    virtual double calculateWeight(const InteractionChainData& aa);
 
    const ParameterTable& cvPars;
    const ParameterTable& univPars;

  private:
    int iUniv;
    float prt_no_inter;
    std::vector<float> vbin_datacv_pip, vbin_datacv_pim, vbin_datasys_pip, vbin_datasys_pim, vbin_datasta_pip, vbin_datasta_pim;
    std::vector<float> vbin_datacv_kap_pip, vbin_datacv_kam_pim, vbin_datasys_kap_pip, vbin_datasys_kam_pim, vbin_datasta_kap_pip, vbin_datasta_kam_pim;
    float aux_par;
  };



  
}
#if defined __clang__
  #pragma clang diagnostic pop
#endif

#endif
