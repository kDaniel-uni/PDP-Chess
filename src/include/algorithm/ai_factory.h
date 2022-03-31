//
// Pdp_chess university project
//

#ifndef PDP_CHESS_AI_FACTORY_H
#define PDP_CHESS_AI_FACTORY_H

namespace pdp_chess {

    class AiFactory {
    public:
        virtual ~AiFactory() {}
        virtual void createAiPlayer() = 0;
    };

}

#endif //PDP_CHESS_AI_FACTORY_H
