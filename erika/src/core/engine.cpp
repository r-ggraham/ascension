#include "core/engine.hpp"

#include "yuki/debug/instrumentor.hpp"
#include "yuki/debug/logger.hpp"

#include "core/game.hpp"

namespace erika {

void
Engine::initialize()
{
    PROFILE_FUNCTION();
    yuki::debug::Logger::info("erika > Initializing game engine...");

    yuki::debug::Logger::notice("erika > Initialized game engine.");
}

void
Engine::run(const std::shared_ptr<Game>& game)
{
    PROFILE_FUNCTION();
    if (!game) {
        yuki::debug::Logger::critical("Engine::run() failed to run: invalid game!");
    }
    yuki::debug::Logger::debug("erika > Engine::run() starting game %s", game->get_window_title().c_str());

    game->initialize();

    // TODO game loop
    game->update(0.16f);
    game->render(0.16f);
}

}
