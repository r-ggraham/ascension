#pragma once

#include <vector>

namespace erika::plugins {

class Renderer;
template<typename T>
class Plugin_Factory;

/**
 * @class Plugin_Manager
 *
 * @brief A class for handling the plugin-based architecture of erika. Handles register, creation & lifecycle of plugins
 */
class Plugin_Manager {
  public:
    Plugin_Manager();

    // TODO: initialize() method for loading plugins. See plugins/plugin_types.hpp for more infomation.

    /**
     * @brief Register a renderer plugin with the manager.
     *
     * @param     name      the name of the renderer plugin
     * @param     factory   a shared pointer to a factory which can create this renderer plugin
     */
    void register_renderer(std::string name, const std::shared_ptr<Plugin_Factory<Renderer>>& factory);
    /**
     * @brief Change the active renderer plugin.
     * This will create a new plugin and call shutdown() & initialize() if appropriate.
     *
     * @param   name    the name of the renderer plugin to create & make active; must be registered
     */
    void change_active_renderer(const std::string& name);

    /**
     * @brief Get a list of the registered renderer plugins.
     *
     * @returns     string list containing the names of all registered renderer plugins
     */
    [[nodiscard]] std::vector<std::string> get_registered_renderers() const;
    /**
     * @brief Get the current active renderer plugin.
     *
     * @returns     a shared pointer to the active renderer plugin, if none are active returns nullptr
     */
    [[nodiscard]] std::shared_ptr<Renderer> get_active_renderer() const;

  private:
    // NOTE: We use vector<pairs> here because the vectors should be so small that it will be more efficient
    // than paying the overhead cost of a map. These vectors are likely to also just be all loaded into cache
    // when we do iterate them anyway.
    std::vector<std::pair<std::string, std::shared_ptr<Plugin_Factory<Renderer>>>> m_registered_renderers;
    std::shared_ptr<Renderer> m_active_renderer;
};

}
