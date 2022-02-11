#ifndef ABSORPTIONDVOLREWEIGHTER_H
#define ABSORPTIONDVOLREWEIGHTER_H

#include "IInteractionChainReweighting.h"
#include "ParameterTable.h"

#if defined __clang__
  #pragma clang diagnostic push
  #pragma clang diagnostic ignored "-Wunused-private-field"
#endif
namespace NeutrinoFluxReweight{
  
  /*! \class AbsorptionReweighter
   *  \brief Reweight a MC survival probabiity when the particles through volumes
   */
  class AbsorptionDVOLReweighter : public IInteractionChainReweighting{
  public:  
    /*!
     * The constructor. Note, we pass central value and single universe parameters in this constructor only. There is thus a 1 to 1 correspondence between an instance of this class and a given universe.
     */
    AbsorptionDVOLReweighter(int iuniv, const ParameterTable& cv_pars, const ParameterTable& univ_pars);
    virtual ~AbsorptionDVOLReweighter();
    //! Look through the InteractionChainData input and identify those Interactions that can be reweighted as part of a chain. We return a vector indicating which elements will be assigned a weight by calculateWeight
    virtual std::vector<bool> canReweight(const InteractionChainData& aa);
    //! calculate a weight for this interaction chain given the central value parameters and the parameters for this universe. The weight is something like: f(cv)/f(MC) * f(univ)/f(cv) where cv in this case  corresponds to the best value of the parameter, given the data. If univ_pars=cv_pars then we are calculating a central value weight. Note, canReweight() should be called to determine which elements of the chain are covered by the weight returned by calculateWeight()
    virtual double calculateWeight(const InteractionChainData& aa);  
    const ParameterTable& cvPars;
    const ParameterTable& univPars;
  private:
    int iUniv;
    float inel_piAl_xsec; 
    float inel_kapAl_xsec_lowP, inel_kapAl_xsec_highP;
    float inel_kamAl_xsec_lowP, inel_kamAl_xsec_highP;

  };



  
}
#if defined __clang__
  #pragma clang diagnostic pop
#endif

#endif
