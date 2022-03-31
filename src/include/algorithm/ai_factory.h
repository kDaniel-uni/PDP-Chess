//
// Pdp_echec university project
//

#ifndef PDP_ECHEC_AI_FACTORY_H
#define PDP_ECHEC_AI_FACTORY_H

namespace pdp_chess {

    class AiFactory {
    public:
        virtual ~AiFactory() {}
        virtual void createAiPlayer() = 0;
    };

}

#endif //PDP_ECHEC_AI_FACTORY_H
