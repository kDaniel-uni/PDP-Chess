//
// Pdp_echec university project
//

#ifndef PDP_ECHEC_AI_FACTORY_H
#define PDP_ECHEC_AI_FACTORY_H


class ai_factory {
public:
    virtual ~ai_factory() {}
    virtual void create_ai_player() = 0;
};


#endif //PDP_ECHEC_AI_FACTORY_H
